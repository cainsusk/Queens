//math_demo.c returns the normal probabiliiy density function num1, 
//or returns the sum of num1, num2
//
//usage: math_demo num1 [num2]

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void normpdf(double x, double *pdf){
	*pdf=(1/(sqrt(2*acos(-1))))*exp(-((pow(x, 2))/2));
}

void add(double x, double y, double *sum) {
	*sum=x+y;
}

void main(int argc, char *argv[]) {
	double sum;
	double pdf;
	argc=argc-1;
	
	if (argc == 0) {
		fprintf(stderr, "usage: math_demo num1 [num2]\n");
		exit(1);
	}
	else if (argc == 1) {
		double x=atof(argv[1]);
		normpdf(x, &pdf);
		printf("phi(x) = %.8f\n", pdf);
	}
	else if (argc == 2) {
		double x=atof(argv[1]);
		double y=atof(argv[2]);
		add(x, y, &sum);
		printf("%6.2f + %6.2f = %6.2f\n", x, y, sum);
	} else {
		fprintf(stderr, "math_demo: please enter 1 or 2 arguments\n");
		exit(1);
	}
}