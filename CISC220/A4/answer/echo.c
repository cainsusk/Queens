//cmdline.c prints any number of arguments input to the program
//
//usage: ./cmdline.c stuff-to-print

#include <stdio.h>

//note, argv is an array of strings which are themselves arrays of char
void main(int argc, char *argv[]) {
	if (argc > 1) {
		for (int i=1;i<argc;i++){
			printf("%s", argv[i]);
			if (i < argc-1){
				printf(" ");
			} else {
				printf("\n");
			}
		}	
	} else {
		printf("\n");
	}
}