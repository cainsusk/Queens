# Makefile for Assignment 5
list_demo : list.o list_utils.o list_demo.c
	gcc -o list_demo list_demo.c list.o list_utils.o

stack_demo : stack.o stack_utils.o stack_demo.c
	gcc -o stack_demo stack_demo.c stack.o stack_utils.o

list_utils.o : list_utils.h list_utils.c
	gcc -c list_utils.c

stack_utils.o : stack_utils.h stack_utils.c
	gcc -c stack_utils.c

list.o : list.c list.h
	gcc -c list.c

stack.o : stack.c stack.h
	gcc -c stack.c

clean :
	rm list_demo *.o