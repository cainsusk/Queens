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

list* list_join(const list *t1, const list *t2){
	if (!is_empty(t1) && is_empty(t2)){
		list_print(t1);
		exit;
	}
	else if (is_empty(t1) && !is_empty(t2)){
		list_print(t2);
		exit;
	}
	else if (!is_empty(t1) && !is_empty(t2)){
		
		list *source = list_copy(t2);
		list *answer = list_copy(t1);
		
		size_t free_space = answer->capacity - list_size(answer);
		
		if(free_space < list_size(source)){// checks if there is enough mem in t1
			size_t defecit = list_size(source) - free_space;
			size_t addition = list_size(answer) + defecit;
			list *tmp = realloc(answer, defecit);
			
			if(!tmp){
				return false; // memory couldnt be allocated
			} else {
				answer = tmp;
			}
		}
		for (int index = 0; index < list_size(source); index++){
			int dest = list_size(answer)+index;
			char src = list_get(source, index);
			list_set(answer, dest, src);
		}
		return answer;
	}
}