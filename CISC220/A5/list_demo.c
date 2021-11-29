#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list_utils.h"

void run_j(const list *l1, const list *l2){
	list *l;
	l = list_join(l1, l2);
	list_print(l);
}

void run_r(list *l1, const int e){
	list *l;
	l = list_remove_all(l1, e);
	list_print(l);
}

void join_spec(){
	int l[] = {1,2,3};
	int s[] = {7,8,9};
	list *list1 = list_init_arr(3, l);
	list *list2 = list_init_arr(3, s);
	list *list3 = list_init_empty();

	run_j(list1, list2);
	run_j(list1, list3);
	run_j(list3, list2);
	run_j(list3, list3);
}

void remove_spec(){
	int l[] = {4,4,4,4,4};
	int s[] = {1,2,2,3,3};

	list *list1 = list_init_arr(5, l);
	list *list2 = list_init_arr(5, s);

	run_r(list1, 3); // possibly fucks w list between runs
	run_r(list2, 1);
	run_r(list2, 2);
	run_r(list1, 4);
}


void main (int argc, char *argv[]){
	join_spec();
	remove_spec();
}

// {
// 	int a[] = {4, 3, 2, 1, 2, 3, 4};
// 	int l[] = {1,2,3};
// 	int s[] = {7,8,9};
// 	list *list1 = list_init_arr(3, l);
// 	list *list2 = list_init_arr(3, s);
// 	list *list3 = list_init_empty();
// 	list ls[] = {list1, list2, list3};
    
//     int len = 3;
// 	for (int i=0; i<len; i++){
// 		list *x = &ls[(i)];
// 		// list *y = &ls[(i+1)%3];

// 		printf("%d, %d, %d\n", i, (i+1)%3);

// 		// list_join(x, y);

// 	}

// 	// list *test = list_init_arr(7, a);
// 	list *ans = list_join(list3, list2);

// 	// test = list_remove_all(test, 1);
	
// 	printf("%d\n", ans->arr[0]);

// 	list_print(ans); 

// 	// list_print(test);
// }