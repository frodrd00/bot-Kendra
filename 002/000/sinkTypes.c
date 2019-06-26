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
  char str1[7];
  char str2[9];
  
  strcpy(str1,"To be ");
  /*  BAD  */
  strcpy(str2,"or not to be");
  /*  BAD  */
  strncpy(str2, str1, 10);

  // 2. String concatenation
  /*  BAD  */
  strcat(str1, str2);
  /*  BAD  */
  strncat(str1, str2, 10);

  puts(str1);
  puts(str2);

  // 3. Memory alteration
  struct Persons person;
  char myname[] = "Pierre de Fermat";
  /*  BAD  */
  memcpy(person.name, myname, strlen(myname)+1);
  person.age = 46;
  printf("person_copy: %s, %d \n", person.name, person.age);

  char dest[] = "oldstring";
  const char src[]  = "newstring";
  printf("Before memmove dest = %s, src = %s\n", dest, src);
  /*  BAD  */
  memmove(dest, src, 9);
  printf("After memmove dest = %s, src = %s\n", dest, src);

  // 4. Formatted string output
  char buffer[20]; 
  int a = 10, b = 20, c = 25; 
  /*  BAD  */
  sprintf(buffer, "Sum of %d and %d is %d", a, b, c); 
  printf("%s", buffer); 

  char buffer2[11]; 
  char* cadena = "geeksforgeeks";  
  /*  BAD  */
  snprintf(buffer2, 13, "%s\n", cadena); 

  // 5. Unformatted string input 
  char passwd[PASSLEN] = {0};
  /*  BAD  */
  gets(passwd);

  // 6. Formatted string input
  /*  BAD  */
  scanf("%s", passwd);
  puts(passwd);

  int day, year;
  char weekday[20], month[20], dtm[100];
  strcpy( dtm, "Saturday March 25 1989" );
  /*  BAD  */
  sscanf( dtm, "%s %s %d  %d", weekday, month, &day, &year );
  printf("%s %d, %d = %s\n", month, day, year, weekday );

  // 7. Array element writes

  char name[5] = "AAAA";
  /*  BAD  */
  name[5] = 'A';

}



/// ###BEGIN_VULNERABLE_LINES###

/// 24,3;24,29

/// 26,3;26,25

/// 30,3;30,20

/// 32,3;32,25

/// 41,3;41,47

/// 49,3;49,23

/// 56,3;56,52

/// 62,3;62,39

/// 67,3;67,14

/// 71,3;71,21

/// 78,3;78,60

/// 85,3;85,13

