#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

const size_t DEFAULT_CAPACITY = 4;

bool add_capacity(list *t);



list *list_init_empty(void) {
    return list_init(DEFAULT_CAPACITY);
}

list *list_init(size_t capacity) {
    list *t = malloc(sizeof(list));
    int *arr = malloc(capacity * sizeof(int));
    if (!arr) {
        return NULL;
    }
    t->arr = arr;
    t->capacity = capacity;
    t->size = 0;
    return t;
}

list *list_init_arr(size_t n, const int a[n]) {
    list *t = malloc(sizeof(list));
    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        return NULL;
    }
    t->arr = arr;
    memcpy(t->arr, a, n * sizeof(int));
    t->capacity = n;
    t->size = n;
    return t;
}

list *list_copy(const list *other) {
    list *t = malloc(sizeof(list));
    int *arr = malloc(other->capacity * sizeof(int));
    if (!arr) {
        return NULL;
    }
    t->arr = arr;
    memcpy(t->arr, other->arr, other->size * sizeof(int));
    t->capacity = other->capacity;
    t->size = other->size;
    return t;
}

size_t list_size(const list *t) {
    return t->size;
}

int list_get(const list *t, size_t index) {
    assert(index < t->size);
    return t->arr[index];
}

int list_set(list *t, size_t index, int elem) {
    assert(index < t->size);
    int old = t->arr[index];
    t->arr[index] = elem;
    return old;
}


bool add_capacity(list *t) {
    int *new_arr = realloc(t->arr, t->capacity * 2 * sizeof(int));
    if (!new_arr) {
        return false;
    }
    t->capacity *= 2;
    t->arr = new_arr;
    return true;
}


bool list_add(list *t, int elem) {
    if (t->size == t->capacity) {
        // out of space in the array; re-allocate the array
        bool ok = add_capacity(t);
        if (!ok) {
            return false;
        }
    }
    t->arr[t->size] = elem;
    t->size++;
    return true;
}

bool list_insert(list *t, size_t index, int elem) {
    assert(index <= t->size);
    if (index == t->size) {
        // add to end of list
        return list_add(t, elem);
    }
    if (t->size == t->capacity) {
        // out of space in the array; re-allocate the array
        bool ok = add_capacity(t);
        if (!ok) {
            return false;
        }
    }
    // move all elements from position index and beyond to
    // the right one position

    // number of elements that need to be moved
    size_t n = t->size - index;
    memmove(&t->arr[index + 1], &t->arr[index], n * sizeof(int));

    // insert element
    t->arr[index] = elem;
    t->size++;
    return true;
}

int list_remove(list *t, size_t index) {
    assert(index < t->size);
    int old = t->arr[index];
    // number of elements that need to be moved
    size_t n = t->size - index - 1;
    if (n > 0) {
        // move the n elements starting at index+1 one position left
        memmove(&t->arr[index], &t->arr[index + 1], n * sizeof(int));
    }
    t->size -= 1;
    return old;
}

char *list_to_string(const list *t) {
    if (t->size == 0) {
        char *s = malloc(3);
        sprintf(s, "[]");
        return s;
    }
    char tmp[100];
    sprintf(tmp, "%d", INT_MIN);
    size_t max_int_len = strlen(tmp);
    char *s = malloc((max_int_len + 2) * t->size + 2);
    char *p = s;
    size_t n = sprintf(p, "[%d", t->arr[0]);
    p += n;
    for (size_t i = 1; i < t->size; i++) {
        n = sprintf(p, ", %d", t->arr[i]);
        p += n;
    }
    sprintf(p, "]");
    return s;
}

int list_to_string2(const list *t, char *buf, const size_t bufsz) {
    if (bufsz == 0) {
        return 0;
    }
    // max number of chars to write
    const int MAX_NBUF = bufsz - 1;

    // number of characters written to buf
    size_t nbuf = 0;
    if (t->size == 0) {
        int n = snprintf(buf, bufsz, "[]");
        if (nbuf > MAX_NBUF) {
            return MAX_NBUF;
        }
        return n;
    }
    size_t bufrem = bufsz;
    int n = snprintf(buf, bufrem, "[%d", t->arr[0]);
    nbuf += n;
    if (nbuf > MAX_NBUF) {
        return MAX_NBUF;
    }
    bufrem -= n;
    // advance buffer pointer for the next write
    buf += n;
    for (size_t i = 1; i < t->size; i++) {
        n = snprintf(buf, bufrem, ", %d", t->arr[i]);
        nbuf += n;
        if (nbuf > MAX_NBUF) {
            return MAX_NBUF;
        }
        buf += n;
        bufrem -= n;
    }
    n = snprintf(buf, bufrem, "]");
    nbuf += n;
    bufrem -= n;
    if (nbuf > MAX_NBUF) {
        return MAX_NBUF;
    }
    return nbuf;
}

void list_print(const list *t) {
    char *s = list_to_string(t);
    printf("%s\n", s);
    free(s);
}

void list_free(list *t) {
    free(t->arr);
}