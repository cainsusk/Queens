#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str1[100];
    char str2[100];
    char str3[100];
    unsigned int x1;
    unsigned int x2;

    // scan empty string
    int n = sscanf("", "%s", str1);
    printf("n = %d\n", n);

    // scan blank string
    n = sscanf("    ", "%s", str1);
    printf("n = %d\n", n);

    // scan non-blank string
    n = sscanf("abc", "%s", str1);
    printf("n = %d, str1 = %s\n", n, str1);

    // scan non-blank string, restrict number of characters read
    n = sscanf("abc", "%2s", str1);
    printf("n = %d, str1 = %s\n", n, str1);

    // scan non-blank string, restrict number of characters read
    n = sscanf("abc xyz", "%2s%s", str1, str2);
    printf("n = %d, str1 = %s, str2 = %s\n", n, str1, str2);

    // scan non-blank string
    n = sscanf("abc xyz", "%s%s", str1, str2);
    printf("n = %d, str1 = %s, str2 = %s\n", n, str1, str2);

    // scan non-blank string
    n = sscanf("abc 1 xyz", "%s%u%s", str1, &x1, str2);
    printf("n = %d, str1 = %s, str2 = %s, x1 = %u\n", n, str1, str2, x1);

    // scan using %[]
    n = sscanf("ccbbaaBCAACB", "%[abc]%[ABC]", str1, str2);
    printf("n = %d, str1 = %s, str2 = %s\n", n, str1, str2);

    // scan a double-quote delimited string having spaces
    n = sscanf(":100:\"string with spaces\":nospaces",
                    ":%u:\"%[^\"]\":%s", &x1, str1, str2);
    printf("n = %d, x1 = %u, str1 = %s, str2 = %s\n", n, x1, str1, str2);
}