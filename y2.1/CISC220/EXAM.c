#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

char* pointer_of_x(char *s) {
  char *p;
  while (*s++) {
    if (*s == 'x'){
      p = s;
    }
  }
  return p;
}

struct student {
  char given[128];
  char last[128];
  int number;
};

int *read_nums(const char* filename, int *num_vals){
  FILE *file = fopen(filename,"r");
  char line[10];

  while (fgets(line, 10, file)){
    *num_vals = *num_vals + 1;
  }
  rewind(file);

  int i = 0;
  int ans[*num_vals];
  while (fgets(line, 10, file)){
    int n = atoi(line);
    ans[i] = n;
    printf("%d, %d\n", i, ans[i]);
    i++;
  }
  return ans;
}

void intersect(int *a, int *b, int *c){
  int k=0;
  for (int i=0; *a[i]; i++){
    for (int j=0; *b[j]; j++){
      if (a[i] == b[j]){
        c[k] = a[i];
        k++;
      }
    }
  }
}

void main (int argc, char *argv[]){
  size_t n = sizeof(argv)/sizeof(argv[0])
  if ( n = 1){
    exit(1);
  }
  f1=argv[1];
  f2=argv[2];
  n1=read_nums(f1);
  n2=read_nums(f2);

  int *c=[400];
  intersect(n1, n2, c);

  for (int i=0; c[i]; i++){
    printf("%d\n", c[i]);
  }
}
