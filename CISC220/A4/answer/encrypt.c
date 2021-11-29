//encrypt.c encrypts a string using a caesar cipher which has offset n
//
//usage: encrypt.c offset text-to-encrypt

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cypher_char(char *c, int offset) {
	if ( *c > 90 && offset > 0 ) {
			*c = (*c - 90) + 64;
	}
	else if ( *c < 65 && offset < 0 ) {
		*c =  91 - (65 - *c);
	}
}

void encrypt(int offset, char string[], int index) {
	int len = strlen(string);
	char str[len+1];
	memset(str, 0, len+1);
	str[len] = '\0';
	
	for (int i=0; i<len; i++) {
		char c = string[i];
		if (offset >= 26) {
			offset = offset% 26;
		}
		
		if (c >= 97 && c <= 122) {
			c = c - 32;  // converts lower to upper
			c = c + offset; 
			cypher_char(&c, offset);
		}
		
		else if (c >= 65 && c <= 90) {
			c = c + offset; 
			cypher_char(&c, offset);
			
		} else {
			c = c;
		}
		strncat(str, &c, 1);
	}
	if (index == 2){
		printf("%s", str);
	} else {
		printf(" %s", str);
	}
}

void main (int argc, char *argv[]) {
	if (argc < 3) {
		fprintf(stderr, "usage: encrypt offset string\n");
		exit(1);
	}
	for (int i=2; i<argc; i++){
		char *txt = argv[i];
		encrypt(atoi(argv[1]), txt, i);
	}
	printf("\n");
	exit(0);
}