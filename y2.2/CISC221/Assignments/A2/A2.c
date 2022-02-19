#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>

int subtract2cp_issafe(int x, int y){

        int w = sizeof(int) * CHAR_BIT;  // number of bits in int Type for given system (can be variable)
        long range = pow(2, w-1);  // -2^{w-1} <= range < 2^{w-1} 

        int unit = (y/abs(y));  // determines if y is negative or positive
        long bigx = (long)x;  // convert x to long for safe comparison with range
        
        for (int i=0; i<abs(y); i++){  // iterate through range(y) and subtract one unit per iteration
                bigx -= unit;  // the sign of y from unit == +- 1

                if (bigx < -1*range || bigx == range){  // if x is outside of the range, return false
                        return 0;
                }
        }
        return 1;  // if the loop completes without exiting the range, return true
}

int main (void){
        int in1, in2;

        scanf("%d %d", &in1, &in2);

        int out = subtract2cp_issafe(in1, in2);

        printf("%d\n", out);
}
