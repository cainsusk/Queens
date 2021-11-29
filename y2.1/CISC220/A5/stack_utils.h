// stack_utils.h

#ifndef STACK_UTILS_H
#define STACK_UTILS_H

typedef bool (*elem_equals_func)(const void *elem1, const void *elem2);

void stack_bottom_insert(stack *s, void *elem);

void stack_reverse(stack *s);

void print_int(void *x);

bool equals_int(void* x, void *y);

bool node_equals(node *n1, node *n2, elem_equals_func equals_func);

#endif /* STACK_UTILS_H */