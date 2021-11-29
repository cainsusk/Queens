#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_utils.h"

void print_int(void *x){
	printf("%d", x);
}

bool equals_int(void* x, void *y){
	if (x == y){
		return true;
	} else {
		return false;
	}
}


void stack_bottom_insert(stack *s, void *elem){
	if (stack_size(s)==0){
		stack_push(s, elem);
	} else {
		void *temp = stack_pop(s);
		stack_bottom_insert(s, elem);

		stack_push(s, temp);
	}
}

void stack_reverse(stack *s){
	if (!(stack_size(s)==0)) {
		void *temp = stack_pop(s);
		stack_reverse(s);

		stack_bottom_insert(s, temp);
	}
}

bool node_equals(node *n1, node *n2, elem_equals_func equals_func){
	if(n1&&n2){
		if ((*equals_func)(n1->elem, n2->elem)){
			node_equals(n1->next, n2->next, equals_func);
			return (*equals_func)(n1->elem, n2->elem);
		}
	}
}

bool stack_equals(const stack *s1, const stack *s2, elem_equals_func equals_func){
	if (stack_size(s1) == 0 && stack_size(s2) == 0){
		return true;
	}
	else if (stack_size(s1) != stack_size(s2)){
		return false;
	} else {
		return node_equals(s1->top, s2->top, equals_func);
	}
}