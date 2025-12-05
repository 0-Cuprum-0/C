#include <stdio.h>
#include <stdlib.h>

int main (){
	double t[10];
	int v[10];
	double *dp;
	dp = t;
	int *ip = v;
	for (int i = 0 ; i< sizeof t / sizeof t[0];i++){
		t[i] = rand() % 99;
		v [i] = rand() %99;
	}
	for (int i =0; i < sizeof t/ sizeof t[1];i++){
		printf("i=%d t[i]= %g;  v[i]= %d; \n", i, t[i], v[i]);
		printf ("dp = %p ip = %d *dp = %g *ip = %d\n", dp , ip, *dp, *ip );
		dp ++;
		ip ++;

	}
	return 0 ;

}
