#include <stdio.h>
void summa (double *v, int *n, double *s){
	while (*n--){
		*s += *v;
		v++;
	}
	printf("%f",*s);
}
int main(){
	double arr[10]= {1.2, 3.245,3,5673}; 
	double sum = 0.0;
	int n = 4;
	summa(arr,&n,&sum);
}
