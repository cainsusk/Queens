#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "list_utils.h"

bool is_empty(const list *t){
	int len=list_size(t);
	if (len == 0){
		return true;
	} else {
		return false;
	}
}

// make function to know if realloc fails or not
bool can_realloc(list *t){
	int *new_arr = realloc(t->arr, t->capacity * 2 * sizeof(int));
    if (!new_arr) {
        return false;
    } else {
    	return true;
    }
}

list* list_join(const list *t1, const list *t2){
	if (!is_empty(t1) && is_empty(t2)){
		return list_copy(t1);
	}
	else if (is_empty(t1) && !is_empty(t2)){
		return list_copy(t2);
	}
	else if (!is_empty(t1) && !is_empty(t2)){
		list *source = list_copy(t2);
		list *answer = list_copy(t1);
		
		for (int index = 0; index < list_size(source); index++){
			if (list_add(answer, list_get(source, index))){
			} else {
				return NULL; // when realloc doesnt work
			}
		}
		list_free(source);
		return answer;
	} else {
		return list_init_empty();
	}
}

list* list_remove_all(list *ls, int target){
	// look for all elemetns that odnt mathch the pattern
	list *t = list_copy(ls);
	size_t len = list_size(t);
	int m = 0; // matches
	list* a = list_init_empty();
	for (int i=0; i<len; i++){
		int elem=t->arr[i];
		// printf("elem: %d\n", elem);
		if (elem != target){
			
			list_add(a, elem);
		}
	}
	list_free(t);
	
	return a;
}

// void list_remove_all(list *t, int target){
// 	size_t len = list_size(t);
// 	for(int i=0; i<len; i++){
// 		//printf("%ld\n", list_size(t));
// 		int elem=list_get(t, i);
// 		printf("%d, %d, %d\n", target, elem, i);
// 		if (elem == target){
// 			list_remove(t, i);
// 		}
// 	}
// } 
