#ifndef LIST_UTILS_H
#define LIST_UTILS_H

bool is_empty(const list *t);

list* list_join(const list *t1, const list *t2);

list* list_remove_all(list *t, int target);

int list_overwrite(list *t, size_t index, int elem);

#endif /* LIST_UTILS_H */