/* Taxonomy Classification: 0000000000020000000200 */

/*
 *  WRITE/READ               	 0	write
 *  WHICH BOUND              	 0	upper
 *  DATA TYPE                	 0	char
 *  MEMORY LOCATION          	 0	stack
 *  SCOPE                    	 0	same
 *  CONTAINER                	 0	no
 *  POINTER                  	 0	no
 *  INDEX COMPLEXITY         	 0	constant
 *  ADDRESS COMPLEXITY       	 0	constant
 *  LENGTH COMPLEXITY        	 0	N/A
 *  ADDRESS ALIAS            	 0	none
 *  INDEX ALIAS              	 2	yes, two levels
 *  LOCAL CONTROL FLOW       	 0	none
 *  SECONDARY CONTROL FLOW   	 0	none
 *  LOOP STRUCTURE           	 0	no
 *  LOOP COMPLEXITY          	 0	N/A
 *  ASYNCHRONY               	 0	no
 *  TAINT                    	 0	no
 *  RUNTIME ENV. DEPENDENCE  	 0	no
 *  MAGNITUDE                	 2	8 bytes
 *  CONTINUOUS/DISCRETE      	 0	discrete
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


int main(int argc, char *argv[])
{
  int i;
  int j;
  int k;
  char buf[10];

  i = 17;
  j = i;
  k = j;

  /*  BAD  */
  buf[k] = 'A';


  return 0;
}


/// ###BEGIN_VULNERABLE_LINES###

/// 62,3;62,12

