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

int is_gecos_empty(const char *s) {
    size_t len = strlen(s);
    assert(s[len] == '\0');
    return s[len + 1] == ':';
} 

record parse_record(char *s) {
    record r;
    // username
    char *str = strtok(s, ":");
    if (!str) {
        return r;
    }
    copy_string(&r.username, str);
    // passwd
    str = strtok(NULL, ":");
    if (!str) {
        return r;
    }
    copy_string(&r.passwd, str);
    // uid
    str = strtok(NULL, ":");
    if (!str) {
        return r;
    }
    r.uid = atoi(str);
    // gid
    str = strtok(NULL, ":");
    if (!str) {
        return r;
    }
    r.uid = atoi(str);
    if (!is_gecos_empty(str)) {
        // gecos
        str = strtok(NULL, ":");
        if (!str) {
            return r;
        }
        copy_string(&r.gecos, str);
    }
    else {
        copy_string(&r.gecos, "");
    }
    // homedir
    str = strtok(NULL, ":");
    if (!str) {
        return r;
    }
    copy_string(&r.homedir, str);
    // shell
    str = strtok(NULL, ":");
    if (!str) {
        return r;
    }
    copy_string(&r.shell, str);
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