#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Thu May 30 14:00:23 2019

@author: flavio-riasc
"""

import glob
import subprocess
import pandas as pd
import sys
import os

# recorre las lineas del AST en busca de las lineas buscadas vulnerables, para obtener las col
def filter_lines(file_line, file_path):
    
    # se utiliza el front-end de clang para obtener el AST y mirar el nodo vulnerable
    process = subprocess.Popen(['clang-check', '-ast-dump',  file_path, '--'], stdout=subprocess.PIPE,  stderr=subprocess.PIPE)
    out, err = process.communicate()
    process.wait()
    splited = out.splitlines();
    sys.stderr.flush()
    sys.stdout.flush()
   
    search =  '<line:' +  str(file_line) + ':' # linea a buscar que contiene las limitaciones del nodo
    get_line = ''
    
    # default
    col1 = '01' 
    col2 = '01'

    for line in splited:
        if search in line.decode('utf-8'):
            if 'BinaryOperator' in line.decode('utf-8'):
                get_line = str(line)
            if 'CallExpr' in line.decode('utf-8'):
                get_line = str(line)
	
    # si get_line no esta vacio 
    #     |   |-BinaryOperator 0x8ef4ec8 <line:66:5, col:25> 'char' '='
    if get_line: 
        try: 
            col1 = get_line.split(':')[2]	 # 5, col
            col1 = col1.split(',')[0] # 5
            
            col2 = get_line.split(':')[3] # 25> 'char' '='
            col2 = col2.split('>')[0]	 # 25

        except: 
            print('---------Error spliting lines-------')
            sys.exit(1)

    return col1, col2
    

# abrir los archivo y buscar la linea vulnerable
def read_files(files):
    
    comment_bad = "/*  BAD  */"
    commnet_ok = "/*  OK  */"

    print("Generando los comentarios en los archivos...")
    for file_path in files: # 
        try:
            with open(file_path) as f: # open files c 
                lines = f.readlines() # read lines       
        except IOError as exc:
                print(exc)   
        
        lines = [x.strip() for x in lines] #quitar espacios
        
        try:
            if "ok" in file_path: # files contains ok string
                indices = [i for i, x in enumerate(lines) if x == commnet_ok] 
                #print('Archivo ', file_path, ' linea ', i+2)
            else:
                indices = [i for i, x in enumerate(lines) if x == comment_bad]
                #print('Archivo ', file_path, ' linea ', i+2)
        except ValueError as e:
            print(e)
            print(file_path)
         
        if len(indices) > 0:
            
            comment = "/// ###BEGIN_VULNERABLE_LINES###"
            vuln_line = ''
            
            for i in indices:
         
                col1, col2 = filter_lines(i+2, file_path)
                vuln_line += "/// " + str(i+2) + "," + col1 + ";" + str(i+2) + "," + col2 + "\n\n"

    
            with open(file_path, 'ab+') as f:
                if not comment in lines:  
                    f.write(str.encode("\n\n" + comment + "\n\n"))
                    f.write(str.encode(vuln_line))
        else:
           print("No se ha encontrado vuln.")

    return files
            
# ejecuta el programa toobad4ml  y captura la salida por consola de las muestras de features         
def toobad4ml(files, path):
    
    print("Generando el dataset...")
    data = [] # lista de caracteristicas por archivo [[car1,car2],[car1,car2]]
    samples_t = 0
    samples_f = 0
    for file_path in files: # 
        
        args = (path, file_path, "--")
        process = subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = process.communicate()
        process.wait()
        splited = out.splitlines();
        sys.stderr.flush()
        sys.stdout.flush()

        # buscar la lineas de muestra
        for lineas in splited:
            
            lineas = lineas.decode('utf-8')
            cadena = lineas.split()
            
            if "Muestra" in cadena:
                
                muestra = cadena[2]
                listChar = muestra.split(';')
                listChar1 = listChar[1:5]
                listChar2 = listChar[5:10]
                
                if all(z != '2' for z in listChar):
                    if any(x != '-1' for x in listChar2)  or  any(x != '0' for x in listChar1):
            
                        if "ok" in file_path:
                            try:     
                                if any(x == '0' for x in listChar2):
                                    print('******Error en la muestra:*****')
                                    print(muestra)
                                    print(file_path)
                                else : 
                                    muestra = muestra + "1" # FALSE non vulnerable files
                                    samples_f +=1
                                    data.append(map(int, muestra.split(';')))
                                #print(muestra)
                            except IndexError as ind:
                                print(ind) 
                                sys.exit(1)
                        else:
                            try:     
                                if any(x == '1' for x in listChar2):
                                    print('******Error en la muestra:*****')
                                    print(muestra)
                                    print(file_path)
                                else: 
                                    muestra = muestra + "0" # TRUE vulnerables files
                                    samples_t +=1
                                    data.append(map(int, muestra.split(';')))
                                #print(muestra)
                            except IndexError as ind:
                                print(ind) 
                                sys.exit(1)
                    
    return data, samples_t, samples_f

# crea el archivo csv con el dataset de las caracteristicas del BOF
def create_csv(data, csv):
    
    head = ['SinkClassification', 'CommandLine', 'EnvironmentVariable', 
            'File', 'Network', 'NumberOfElementsCopiedWithinBounds', 'ArrayWriteIndexWithinBounds',
			'FormatStringPrecisionWithinBounds', 'StringCopyWithinBounds', 
            'IsCharacterCaseConversionSink', 'Vulnerable?' ]
    
    df = pd.DataFrame(data)
    df.to_csv(csv, header=head, index=False)

# ayuda de como usar el bot
def print_usage():
    print('bot.py \"path_archivos_vulnerables\" \"./toolbad4ml\" \"csv_file\"\n' +
          'Ejemplo: python bot.py \"000/*/*/*.c\" \"/home/user/eclipse-workspace/toobad4ml/bin/TOOBAD4ML\" \"list.csv\"')
    sys.exit(0)

    
# la primera funcion que ejecuta el programa
def main():

    if len(sys.argv) == 4:
        if sys.argv[1] == '-h':
            print_usage()

        else:
            # recorrer los archivos 
            #path = '000/*/*/*.c'
            path_vuln = sys.argv[1]
            path_toolbad4ml = sys.argv[2]
            path_csv = sys.argv[3]

            files = glob.glob(path_vuln)
            read_files(files)

            if os.path.exists(path_toolbad4ml) and os.path.isfile(path_toolbad4ml):
                data, samples_t, samples_f = toobad4ml(files, path_toolbad4ml)
            else:
                print("Ruta de toolbad4ml no valida")
                print_usage()
                sys.exit(1)
            
            if path_csv.endswith('.csv'):
                create_csv(data, path_csv)
            else: 
                print("Extension csv no valida")
                print_usage()
                sys.exit(1)
            
            print("Total number of files: ", len(files))
            print("Number of samples generated: ", len(data))
            print("Number of samples labeled vulnerable: ", samples_t)
            print("Number of samples labeled not vulnerable: ", samples_f)
            print("Fin")
    else:
        print("Numero de argumentos invalidos")
        print_usage()

if __name__== "__main__":
    main()