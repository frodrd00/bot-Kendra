#include <stdio.h>
#include <string.h>

#define PASSLEN 8
#define SIZE_OK(x) ((x) < (7) ? (1) : (0))
#define ALIAS 0
#define MAX 15

struct Persons{
  char name[2];
  int age;
};


int main() {

 
  // 1. String copy
  char str1[50];
  char str2[50];
  
  strcpy(str1,"To be ");
  /*  OK  */
  strcpy(str2,"or not to be");
  /*  BAD  */
  strncpy(str2, str1, 10);

  // 2. String concatenation
  /*  OK  */
  strcat(str1, str2);
  /*  OK  */
  strncat(str1, str2, 6);

  puts(str1);
  puts(str2);

  // 3. Memory alteration
  char dest[] = "old";
  const char src[]  = "newstring";
  printf("Before memmove dest = %s, src = %s\n", dest, src);
  /*  OK  */
  memmove(dest, src, 2);
  printf("After memmove dest = %s, src = %s\n", dest, src);

  // 4. Formatted string output
  char buffer[50]; 
  int a = 10, b = 20, c = 25; 
  /*  OK  */
  sprintf(buffer, "Sum of %d and %d is %d", a, b, c); 
  printf("%s", buffer); 

  char buffer12[50]; 
  char a2[] = "300"; int b2 = 20, c2 = 320; 
  /*  OK  */
  sprintf(buffer12, "Sum of %2.3s and %d is %d", a2, b2, c2); 
  printf("%s", buffer12); 

  char buffer2[11]; 
  char* cadena = "geeksforgeeks";  
  /*  OK  */
  snprintf(buffer2, 6, "%s\n", cadena); 

  // 5. Unformatted string input 
  char buf[MAX]; 
  /*  OK  */
  fgets(buf, MAX, stdin); 

  // 7. Array element writes

  char name[5] = "AAAA";
  /*  OK  */
  name[5] = 'A';

}




/// ###BEGIN_VULNERABLE_LINES###

/// 24,3;24,29

/// 30,3;30,20

/// 32,3;32,24

/// 42,3;42,23

/// 49,3;49,52

/// 55,3;55,60

/// 61,3;61,38

/// 66,3;66,24

/// 72,3;72,13

