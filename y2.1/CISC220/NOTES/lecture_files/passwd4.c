#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct record record;
struct record {
    char *username;
    char *passwd;
    unsigned uid;
    unsigned gid;
    char *gecos;
    char *homedir;
    char *shell;
};

void copy_string(char **dest, const char *src) {
    size_t len = strlen(src);
    *dest = malloc(len);
    strcpy(*dest, src);
}

record parse_record(char *s) {
    record r;
    size_t max_width = 64;
    r.username = malloc(max_width);
    r.passwd = malloc(max_width);
    r.gecos = malloc(max_width);
    r.homedir = malloc(max_width);
    r.shell = malloc(max_width);
    int chars_read = 0;
    int n = sscanf(s, "%63[^:]:%63[^:]:%u:%u:%n", 
                r.username,
                r.passwd,
                &r.uid,
                &r.gid,
                &chars_read);
    if (n < 4) {
        return r;
    }
    if (s[chars_read] == ':') {
        // gecos field is empty
        r.gecos[0] = '\0';
        s = s + chars_read + 1;
        n = sscanf(s, "%63[^:]:%63[^:]",
                r.homedir,
                r.shell);
    }
    else {
        s = s + chars_read;
        n = sscanf(s, "%63[^:]:%63[^:]:%63[^:]",
                r.gecos,
                r.homedir,
                r.shell);
    }
    return r;
}

void print_record(record r) {
    printf("username : %s\n", r.username);
    printf("password : %s\n", r.passwd);
    printf("uid      : %u\n", r.uid);
    printf("gid      : %u\n", r.gid);
    printf("gecos    : %s\n", r.gecos);
    printf("homedir  : %s\n", r.homedir);
    printf("shell    : %s\n", r.shell);
}

int main(void) {
    FILE *f = fopen("/etc/passwd", "r");
    if (!f) {
        fprintf(stderr, "Could not open /etc/passwd for reading");
        exit(1);
    }
    char buf[100];
    while (fgets(buf, 100, f)) {
        record r = parse_record(buf);
        print_record(r);
    }
    fclose(f);
}