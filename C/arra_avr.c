#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double avr (double v[],int n){
	double sum;
	for (int i=0; i < n; i++){
		sum +=v[i];
	}
	if (n!=0){

		printf ("%f\n", sum/n );
		return sum/n;
	}
	else 
		return 0;
}
double stand ( double v[], int n){
	double sum = 0;
	double sum2 = 0;
	for (int i = 0; i< n;i++){
		sum += v[i];
		sum2 += v[i]*v[i];
		
	}
	return sqrt(n * sum2 - sum * sum) / n;
}
int main(){
double arr[20] = {1,2,3,4,5.6};
int count = 5;
avr(arr, count);
printf("%f\n", stand(arr,count));

}
