#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
	// 2. Number of elements Copied within bounds
	char str3[] = "To be or not to be";
	char str4[4];
	/*  OK  */
	strncpy(str4, str3, 3);  // null terminator
	puts(str4);

	// 3. Array write index within bounds. 
	char array[4] = {'A', 'B', 'C', '\0'};
	/*  OK  */
	array[2] = 'A';
	printf("%s\n", array);

	char array1[4] = {"REQ"};
	/*  OK  */
  	array1[2] = 'A';
  	printf("%s\n", array1);

	// 4. Format String Precision Within Bounds
	char *str = "QWERYUIOPASDFGHJKLNZXCVBNMQWEQWE";
	char buf[42];
  	/*  OK  */
	sprintf(buf, "<%.10s>", str);

	char *str1 = "QWERYUIOPASDFGHJKLNZXCVBNMQWEQWE";
	char buf1[42];
  	/*  OK  */
	sprintf(buf1, "<%5.2s>", str1);
  	printf("%s\n", buf1);

	char buffer[17]; 
  	char* s = "geeksforgeeks";  
 	 /*  OK  */
  	snprintf(buffer, 4, "%s\n", s); 
  	printf("string:\n%s\n", buffer); 

 	 char str2[14];
 	printf("Enter name: ");
 	 /*  OK  */
 	scanf("%5s", str2);
 	printf("Entered Name: %s\n", str2);

 	// 5. Srting Copy within bounds
 	char strr[10];
  	/*  OK  */ 
	strcpy(strr,"To be ");

	//8. Is character case Conversion sink
 	char up = 'a';
  	/*  OK  */
 	up = toupper(up);
 	printf("%c\n", up);

}


/// ###BEGIN_VULNERABLE_LINES###

/// 10,2;10,23

/// 16,2;16,13

/// 21,4;21,16

/// 28,2;28,29

/// 33,2;33,31

/// 39,4;39,33

/// 45,3;45,20

/// 51,2;51,22

/// 56,3;56,18

