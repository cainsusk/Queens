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

int str_cut(char *str, int begin, int len){
    int l = strlen(str);

    if (len < 0) len = l - begin;
    if (begin + len > l) len = l - begin;
    memmove(str + begin, str + begin + len, l - len + 1);

    return len;
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

int delimFields(char *s){
  int count = 1;
  int inString = 0;

  if (!strrchr(s, '\n')){
    strcat(s, (char*) "\n");
  }
  for (int i=0; s[i]; i++){
    inString = checkInString(s[i], inString);
    if ((s[i] == ',') && inString == 0){
      s[i]= '>';
      count ++;
    }
  }
  return count;
}

void average(FILE *file, int ass, int lines){
  int grades[ass];
  memset(grades, 0, (4*ass) * sizeof(char));
  int missing[ass];
  memset(missing, 0, (4*ass) * sizeof(char));
  char line[100];
  while (fgets(line, 100, file)){
    delimFields(line);
    for (int i=0; i<ass; i++){
      char *a = malloc(20*sizeof(char));
      a = strrchr(line, '>');
      int grade = atoi((a+1));

      if (grade == 0){
        missing[i] = missing[i] + 1;
      }else{
        grades[i] = grades[i] + grade;
      }
      str_cut(line, strlen(line)-strlen(a), strlen(a));
    }
  }

  int assNum = 1;
  for (int i=ass; i>0; i--){
    float finAss = lines - missing[i-1];
    printf("\nA%d: %.1f\n",assNum++, (float) grades[i-1]/finAss);
  }
}

int main() {
  FILE *file = fopen("grades2.txt","r");

  if (!file){
    fprintf(stderr, "Could not open csv for reading");
    exit(1);
  }

  int lines = countLines(file);

  char line[100];
  fgets(line, 100, file);
  rewind(file);

  int fields = delimFields(line);
  int ass = fields - 2;

  average(file, ass, lines);

  }
