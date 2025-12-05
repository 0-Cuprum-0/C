#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calk (double (*f) (double), double a, double b, int n){
	double l = (b-a)/n;
	double s;
	double sum;
	for (int i=0; i<n; i++){
		double h =f( a + i*l);
		s = l*h;
		sum += s;
	}
	printf("%f", sum);
}
