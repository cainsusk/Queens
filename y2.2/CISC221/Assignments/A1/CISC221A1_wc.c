#include <stdio.h>
#include <string.h>


int count (char input[], char target){
        int count = 0;
        int len = strlen(input);
        for (int i = 0; i < len; i++){
                char c = input[i];
                if (c == target){
                        count++;
                }
                if (c == '\0'){
                        break;
                }
        }
        return count;
}


int count_char (char input[]){
        int count = 0;
        int len = strlen(input);
        for (int i = 0; i < len; i++){
                char c = input[i];
                if (c == '\0'){
                        break;
                }else{
                        count++;
                }
        }
        return count;
}


int count_words (char input[], char targets[]){
        int count = 0;
        int len = strlen(input);
        for (int i = 0; i < len; i++){
                char c = input[i];
                if (strchr(targets, c) != NULL){
                        count++;
                        printf("%c", c);
                }
                if (c == '\0'){
                        break;
                }
        }
        return count;
}


int main (void){ /*int argc, char *argv[]*/

        /* for some reason input is in targets and i must figure out why this is happening
         * also, gotta add a count_lines function 
         */

        const char targets[5] = {'.', '\t', ';', ' ', ':'};

        char input[300];
        scanf("%[^\x04]%*c", input);
        

        printf("%s\n", targets);
 /*
        int targets_count[5]; 
        for (int i=0; i<5; i++){
                targets_count[i] = count(input, targets[i]);
        }

        for (int i=0; i<5; i++){
                printf("'%c': %d\n\n", targets[i], targets_count[i]);
        }

        int w = count_words(input, targets);
        printf("words: %d\n", w);


        
        int spaces = count(input, ' ');
        int lines = count(input, '\n');
        int tab = count(input, '\t');
        int period = count(input, '.');
        int semico = count(input, ';');
        int colon = count(input, ':');

        printf("%d\n", spaces);

        int len = strlen(input);
        for (int i = 0; i < len; i++){
                char c = input[i];
                if (c == ' '){
                        printf("SPACE ");
                }
                if (c == '\0'){
                        break;
                }
        }


        while (1 == sscanf(input, "%c", &c)){
                if (c == ' '){
                        printf("SPACE");
                }
        }
  */              



        
}
