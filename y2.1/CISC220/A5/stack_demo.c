#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_utils.h"

void run_r(stack *st){
	print_elem_func e = &print_int;
	stack_print(st, e);
	stack_reverse(st);
	stack_print(st, e);
	printf("\n");
}

void reverse_spec(){
	stack *st1 = stack_init();
	for (int i=0; i<1; i++){
		stack_push(st1, i);
	}
	stack *st2 = stack_init();
	for (int i=0; i<3; i++){
		stack_push(st2, i);
	}
	stack *st3 = stack_init();

	run_r(st1);
	run_r(st2);
	run_r(st3);
}

void run_e(stack *st1, stack *st2){
	print_elem_func e = &print_int;
	elem_equals_func eq = &equals_int;

	stack_print(st1, e);
	stack_print(st2, e);

	bool a = stack_equals(st1, st2, eq);
	printf(a ? "true\n" : "false\n");
}

void equals_spec(){
	stack *st1 = stack_init();
	for (int i=0; i<1; i++){
		stack_push(st1, i);
	}
	stack *st2 = stack_init();
	for (int i=1; i>0; i--){
		stack_push(st2, i);
	}
	stack *st3 = stack_init();
	for (int i=0; i<3; i++){
		stack_push(st3, i);
	}
	stack *st4 = stack_init();
	for (int i=3; i>0; i--){
		stack_push(st4, i);
	}
	stack *st5 = stack_init();

	run_e(st5, st5);
	run_e(st1, st1);
	run_e(st1, st2);
	run_e(st3, st3);
	run_e(st3, st4);
}

void main(int argc, char *argv[]){
	reverse_spec();
	equals_spec();
}