#include<stdio.h>

int countLines(FILE *file) {
  int lines = 0;
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

int countCommas(char *s){
  int i;
  for (i=0; s[i]; s[i]==',' ? i++ : *s++);
  return i;
}


int main() {
  char first[21], last[21];
  int grade;

  int i = 0;

  FILE *file = fopen("grades1.txt","r");

  if (!file){
    fprintf(stderr, "Could not open /etc/passwd for reading");
    exit(1);
  }
  int lines = countLines(file);
  printf("LINES: 0-%d\n", lines);

  char line[100];
  fgets(line, 100, file);
  int fields = countCommas(line);
  printf("FIELDS: 0-%d\n", fields);
  char buf[100];
    while (fgets(buf, 100, file)) {
      sscanf(buf, "\"%[^\"^,]\", \"%[^\"^,]\", %d", last, first, &grade);
      printf("%s, %s, %d\n", first, last, grade);
    }
}
//   while(fscanf(file, "\"%[^,^\"]\", \"%[^,^\"]\", %d", last, first, &grade)==1){
//     printf("\n%d:\n", i);
//     printf("%s, %s, %d\n", last, first, grade);
//     i++;
//   }
//   fclose(file);
// }
