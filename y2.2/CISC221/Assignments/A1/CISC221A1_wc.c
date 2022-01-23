#include <stdio.h>
#include <string.h>


int count (char input[], char target){
        int count = 0;
        int len = strlen(input);
        for (int i = 0; i < len; i++){  // iterate over input and count each target
                char c = input[i];
                if (c == target){
                        count++;
                }
                if (c == '\0'){  // end of input
                        break;
                }
        }
        return count;
}


int count_chars (char input[]){
        int count = 0;
        int len = strlen(input);
        for (int i = 0; i < len; i++){ //  count each char by iterating over input
                char c = input[i];
                if (c == '\0'){ // end of input
                        break;
                }else{
                        count++;
                }
        }
        return count;
}


int count_words (char input[], const char targets[]){
        int count = 0;
        _Bool tar_before = 0;  // checks if there was a delimiter before the current char to ignore it
        int len = strlen(input);
        for (int i = 0; i < len; i++){  // iterate through input to look for delimiters (targets)
                char c = input[i];
                if (strchr(targets, c) != NULL){  // incrament count for each word
                        if (tar_before != 1){        
                                count++;
                        }
                        tar_before = 1;
                }
                else if (c == '\0'){  // end of file
                        break;
                }else{
                        tar_before = 0;
                }
        }
        return count;
}


int main (void){ 

        char input[128];
        scanf("%[^\x04]%*c", input);  // take input until ctrl-d

        const char *targets = ".\t; :\n"; // define delimiters
 
        int w = count_words(input, targets);  // count words, chars, and lines
        int c = count_chars(input);
        int n = count(input, '\n');

        printf("\t%d\t%d\t%d\n", n, w, c); // output
}
