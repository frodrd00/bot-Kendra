#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
	// 2. Number of elements Copied within bounds
	char str3[] = "To be or not to be";
	char str4[4];
	/*  BAD  */
	strncpy(str4, str3, 5);  
	puts(str4);

	char str5[] = "To be or not to be";
	char str6[4];
	/*  BAD  */
	strncpy(str6, str5, sizeof(str6)); 
	puts(str6);

	// 3. Array write index within bounds. 
	char array[4] = {'A', 'B', 'C', '\0'};
	/*  BAD  */
	array[5] = 'A';
	printf("%s\n", array);

	char array1[4] = {"REQ"};
	/*  BAD  */
  	array1[5] = 'A';
  	printf("%s\n", array1);

	// 4. Format String Precision Within Bounds
	char *str = "QWERYUIOPASDFGHJKLNZXCVBNMQWEQWE";
	char buf[32];
  	/*  BAD  */
	sprintf(buf, "<%.32s>", str);

	char *str1 = "QWERYUIOPASDFGHJKLNZXCVBNMQWEQWE";
	char buf1[32];
  	/*  BAD  */
	sprintf(buf1, "<%15.15s>", str1);
  	printf("%s\n", buf1);

	char buffer[7]; 
  	char* s = "geeksforgeeks";  
 	 /*  BAD  */
  	snprintf(buffer, 8, "%s\n", s); 
  	printf("string:\n%s\n", buffer); 

 	 char str2[4];
 	printf("Enter name: ");
 	 /*  BAD  */
 	scanf("%5s", str2);
 	printf("Entered Name: %s\n", str2);

 	// 5. Srting Copy within bounds
 	char strr[5];
  	/*  BAD  */ 
	strcpy(strr,"To be ");

}


/// ###BEGIN_VULNERABLE_LINES###

/// 10,2;10,23

/// 16,2;16,34

/// 22,2;22,13

/// 27,4;27,16

/// 34,2;34,29

/// 39,2;39,33

/// 45,4;45,33

/// 51,3;51,20

/// 57,2;57,22

