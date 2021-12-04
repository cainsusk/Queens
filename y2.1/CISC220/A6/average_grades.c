#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

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



//   printf("'%c'=='%c'\n", c, tgStr);
//   if (c == tgStr){
//     if (b == false){
//       printf("START_STR-");
//       return true;
//     }
//   }
//   if (c == tgStr){
//     if (b == true){
//       printf("END_STR-");
//       return false;
//     }
//   }
// }

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
  int count = 1;
  int inString = 0;
  for (int i=0; s[i]; i++){
    inString = checkInString(s[i], inString);
    if (s[i]==',' && inString == 0){
      count++;
    }
  }
  return count;
}

// void idFields(char *s, int fields, char *types[]){
//   char type = '\0';
//   int num_t = 0;
//
//   for (int i=0; s[i]; i++){
//     if (s[i] == ',') {
//       if (type == '\0'){
//         *types[num_t++] = 'n';
//       }
//       if (isdigit(type)) {
//         *types[num_t++] = 'd';
//       } else {
//         *types[num_t++] = 's';
//       }
//     }
//   }
// }


// int identifyFields(FILE *file){
//   char line[100];
//   int fields = INT_MAX;
//   while (fgets(line, 100, file)) {
//     int commas = countCommas(line);
//     if (commas < fields){
//       fields = commas;
//     }
//   }
//   rewind(file);
//   return fields;
// }

// int parseLine(char *str, int commas){
//     int grades[(commas+1)-2]
//     int data = NULL;
//     int field = 0;
//     char last = NULL;
//
//     bool inString = false;
//     int len = strlen(line);
//     for (int c=0; c<len; c++){
//
//       if (line[c] == ',' || c == len-1){
//         if (data != NULL){
//           grades[field] = data;
//           data = NULL;
//         }
//         field++;
//       }
//
//       if (isdigit(line[c]) && isdigit(last)){
//
//       }
//
//       if else (line[c] == '%d'){
//         char *num[4];
//         num[0] = line[c];
//       }
//
//       last = line[c];
//     }
//   }

//   char *out[commas];
//   bool inString = false;
//   int num = 0;
//   out[num++] = str;
//   inString = checkInString(str, inString);
//   while (num < commas && str && !inString && (str = strchr(str, ','))) {
//       *str = 0;           // nul-terminate previous field
//       out[num++] = ++str; // save start of next field
//   }
//   return out;
// }

int main() {
  char first[21], last[21];
  int grade1;
  int grade2;
  int grade3;
  int grade4;

  FILE *file = fopen("grades2.txt","r");

  if (!file){
    fprintf(stderr, "Could not open csv for reading");
    exit(1);
  }

  int lines = countLines(file);
  printf("LINES: %d\n", lines);

  // int fields = identifyFields(file);
  // printf("FIELDS: %d\n", fields);
  char line[100];
  fgets(line, 100, file);

  int fields = countFields(line);
  printf("FIELDS: %d\n", fields);

  // char *types = (char*) malloc(1+fields*sizeof(char));
  // types[fields] = '\0';
  // idFields(line, fields, types);
  // printf("%d", types);
  // free(types);



  char buf[100];
    while (fgets(buf, 100, file)) {
      sscanf(buf, "\"%*[^\"]\", \"%*[^\"]\", %d, %d, %d, %d", &grade1, &grade2, &grade3, &grade4);
      printf("%d %d %d %d\n", grade1, grade2, grade3, grade4);
    }



}
  // char buf[100];
  //   while (fgets(buf, 100, file)) {
  //     sscanf(buf, "\"%*[^\"]\", \"%*[^\"]\", %d", &grade);
  //     printf("%d\n", grade);
  //   }

//   while(fscanf(file, "\"%[^,^\"]\", \"%[^,^\"]\", %d", last, first, &grade)==1){
//     printf("\n%d:\n", i);
//     printf("%s, %s, %d\n", last, first, grade);
//     i++;
//   }
//   fclose(file);
// }
