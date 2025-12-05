#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void pvect(double v[], int n){
	printf("[");
	for (int i = 0; i < n; i++){
		printf("%g", v[i]);
	}
	printf("]\n");
}
void sum(double x[], double y[], double s[], int n){
	while (n>= 0){
		n--;
		s[n] = x[n] + y[n];
	}
}
double avg (double v[], int n){
	double rslt = 0.0;
	for(int i = 0; i < n; i++){
		rslt += v[i];	
	}
	if(n==0)
		return 0;
	else 
		return rslt/n;
}
int main(int argc, char *argv[]){
	double x[MAX];
	double y[MAX];
	int n =0;
	int i = 0;

	double s[MAX];

	while(scanf("%lf %lf", &x[i], &y[i])==2){
		i++;
	}
	printf("przeczytalam %d par liczb \n", i);
	
	pvect(x ,n);
	pvect(y , n);
	
	sum(x, y, s, n);
	printf("%d\n", s);
	avg (x,n);
	avg (y,n);
	return 0;

}
