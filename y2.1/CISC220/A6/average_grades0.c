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

int countFields(char *s){
  int count = 0;
  int inString = 0;

  if (!strrchr(s, '\n')){
    strcat(s, (char*) "\n");
  }
  for (int i=0; s[i]; i++){
    inString = checkInString(s[i], inString);
    if ((s[i] == ',' || s[i] == '\n' ) && inString == 0){
      count++;
    }
  }
  return count;
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

  int fields = countFields(line);
  printf("FIELDS: %d\n", fields);


  }
