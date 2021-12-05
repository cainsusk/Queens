#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int checkInString(char c, int b){
  char toggle = '\"';
  if (c != toggle){
    return b;
  }
  if (c == toggle && b == 0){
    return 1;
  }
  if (c == toggle && b != 0){
    return 0;
  }
}

int countLines(FILE *file) {
  int lines = 1;
  int c;
  int last = '\n';
  while (EOF != (c = fgetc(file))) {
    if (c == '\n' && last != '\n') {
      ++lines;
    }
    last = c;
  }
  rewind(file);
  return lines;
}

int countFields(char *s, char *types){
  char type = 'n';
  int count = 0;
  int inString = 0;

  if (!strrchr(s, '\n')){
    strcat(s, (char*) "\n");
  }

  printf("\n");
  for (int i=0; s[i]; i++){
    printf("%c", s[i]);
    if (isalpha(s[i]) || s[i] == '\"') {
      type = 's';
    }

    if (isdigit(s[i])) {
      type = 'd';
    }

    inString = checkInString(s[i], inString);
    if ((s[i] == ',' || s[i] == '\n' ) && inString == 0){
      *types++ = type;
      type = 'n';
      count++;
    }
  }
  return count;
}

char* translateTypes(char *types, char *ans){
  int count;
  char add[21];
  for (count=0; types[count]; count++){
    switch (types[count]) {
      case 'n':
      strcat(add, " ,");
      case 'd':
      strcat(add, " %d,");
      case 's':
      strcat(add, " \"%*[^\"]\", ");
    }
    strcat(ans, add);
    memset(add, 0, sizeof(add));
  }
}


int main() {
  char first[21], last[21];
  int grade1;
  int grade2;
  int grade3;
  int grade4;

  FILE *file = fopen("grades3.txt","r");

  if (!file){
    fprintf(stderr, "Could not open csv for reading");
    exit(1);
  }

  int lines = countLines(file);
  printf("LINES: %d\n", lines);

  char line[100];
  fgets(line, 100, file);

  rewind(file);
  char buf[100];
  char *types = (char*) (malloc(50*sizeof(char)));
  char *translation = (char*) (malloc(50*sizeof(char)));
    while (fgets(buf, 100, file)) {
      int fields = countFields(buf, types);
      translateTypes(types, translation);
      printf("FIELDS: %d\n", fields);
      printf("TYPES: %s\n", types);
      printf("TYPES: %s\n", translation);


      types = (char*) (realloc(0, 50*sizeof(char)));
    }
  }
