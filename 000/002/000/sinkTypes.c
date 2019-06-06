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
  char str1[10];
  char str2[6];
  
  strcpy(str1,"To be ");
  /*  BAD  */
  strcpy(str2,"or not to be");
  /*  BAD  */
  strncpy(str2, str1, 10);

  // 2. String concatenation
  /*  BAD  */
  strcat(str1, str2);
  /*  BAD  */
  strncat(str1, str2, 6);

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
  char buffer[50]; 
  int a = 10, b = 20, c = 25; 
  /*  BAD  */
  sprintf(buffer, "Sum of %d and %d is %d", a, b, c); 
  printf("%s", buffer); 

  char buffer12[50]; 
  char a2[] = "300"; int b2 = 20, c2 = 320; 
  /*  BAD  */
  sprintf(buffer12, "Sum of %2.3s and %d is %d", a2, b2, c2); 
  printf("%s", buffer12); 

  char buffer2[11]; 
  char* cadena = "geeksforgeeks";  
  /*  BAD  */
  snprintf(buffer2, 6, "%s\n", cadena); 

  // 5. Unformatted string input 
  char passwd[PASSLEN] = {0};
  /*  BAD  */
  gets(passwd);

  char buf[MAX]; 
  /*  BAD  */
  fgets(buf, MAX, stdin); 

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

