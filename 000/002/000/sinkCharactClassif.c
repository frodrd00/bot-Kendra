#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main () {
	// 2. Number of elements Copied within bounds
	char str3[] = "To be or not to be";
	char str4[4];
	/*  BAD  */
	strncpy(str4, str3, 4);  // null terminator
	puts(str4);

	char str5[] = "To be or not to be";
	char str6[4];
	/*  BAD  */
	strncpy(str6, str5, sizeof(str6)); // null terminator
	puts(str6);

	// 3. Array write index within bounds. 
	char array[4] = {'A', 'B', 'C', '\0'};
	/*  BAD  */
	array[3] = 'A';
	printf("%s\n", array);

	char array1[4] = {"REQ"};
	/*  BAD  */
  	array1[3] = 'A';
  	printf("%s\n", array1);

	// 4. Format String Precision Within Bounds
	char *str = "QWERYUIOPASDFGHJKLNZXCVBNMQWEQWE";
	char buf[32];
  	/*  BAD  */
	sprintf(buf, "<%.32s>", str);

	char *str1 = "QWERYUIOPASDFGHJKLNZXCVBNMQWEQWE";
	char buf1[32];
  	/*  BAD  */
	sprintf(buf1, "<%5.12s>", str1);
  	printf("%s\n", buf1);

	char buffer[7]; 
  	char* s = "geeksforgeeks";  
 	 /*  BAD  */
  	snprintf(buffer, 6, "%s\n", s); 
  	printf("string:\n%s\n", buffer); 

 	 char str2[4];
 	printf("Enter name: ");
 	 /*  BAD  */
 	scanf("%5s", str2);
 	printf("Entered Name: %s\n", str2);

 	// 5. Srting Copy within bounds
 	char strr[10];
  	/*  BAD  */ 
	strcpy(strr,"To be ");

	//8. Is character case Conversion sink
 	char up = 'a';
  	/*  BAD  */
 	up = toupper(up);
 	printf("%c\n", up);

}


