/* Taxonomy Classification: 0000300605130000000310 */

/*
 *  WRITE/READ               	 0	write
 *  WHICH BOUND              	 0	upper
 *  DATA TYPE                	 0	char
 *  MEMORY LOCATION          	 0	stack
 *  SCOPE                    	 3	inter-file/inter-proc
 *  CONTAINER                	 0	no
 *  POINTER                  	 0	no
 *  INDEX COMPLEXITY         	 6	N/A
 *  ADDRESS COMPLEXITY       	 0	constant
 *  LENGTH COMPLEXITY        	 5	non-linear expr
 *  ADDRESS ALIAS            	 1	yes, one level
 *  INDEX ALIAS              	 3	N/A
 *  LOCAL CONTROL FLOW       	 0	none
 *  SECONDARY CONTROL FLOW   	 0	none
 *  LOOP STRUCTURE           	 0	no
 *  LOOP COMPLEXITY          	 0	N/A
 *  ASYNCHRONY               	 0	no
 *  TAINT                    	 0	no
 *  RUNTIME ENV. DEPENDENCE  	 0	no
 *  MAGNITUDE                	 3	4096 bytes
 *  CONTINUOUS/DISCRETE      	 1	continuous
 *  SIGNEDNESS               	 0	no
 */

/*
Copyright 2004 M.I.T.

Permission is hereby granted, without written agreement or royalty fee, to use, 
copy, modify, and distribute this software and its documentation for any 
purpose, provided that the above copyright notice and the following three 
paragraphs appear in all copies of this software.

IN NO EVENT SHALL M.I.T. BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, 
INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE 
AND ITS DOCUMENTATION, EVEN IF M.I.T. HAS BEEN ADVISED OF THE POSSIBILITY OF 
SUCH DAMANGE.

M.I.T. SPECIFICALLY DISCLAIMS ANY WARRANTIES INCLUDING, BUT NOT LIMITED TO 
THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, 
AND NON-INFRINGEMENT.

THE SOFTWARE IS PROVIDED ON AN "AS-IS" BASIS AND M.I.T. HAS NO OBLIGATION TO 
PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
*/

#include <string.h>

int main(int argc, char *argv[])
{
  int i;
  char src[4106];
  char buf[10];

  memset(src, 'A', 4106);
  src[4106 - 1] = '\0';
  i = 4107;

  /*  BAD  */
  strncpy(buf, src, 4106 % i);


  return 0;
}


/// ###BEGIN_VULNERABLE_LINES###

/// 62,3;62,29

