#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "calk.h"

double f(double x){
	return sqrt(x);
}
int main(int argc, char **argv){
	double a = argc >1 ? atof (argv[1]) : 0;
	double b = argc > 2 ? atof(argv[2]): M_PI;
	int n = argc  > 3 ? atof(argv [3]) : 1000;

	printf("Int <%g,%g>[%i] (x*sin(x)) = %g\n ",a,b,n,calk(f,a,b,n) );
	return 0;
}
