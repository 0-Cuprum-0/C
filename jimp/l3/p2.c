#include <stdio.h>

int usun_ujemne(double v[], int n)
{
        /* Usuwa ujemne elementy z wektora v */
        int i = 0;
	int j =0;
        while (n--) {

                if (v[j] >= 0){    /* jeśli element jest dodatni */
                        v[i] = v[j];
			i++;
		}  
	
                       j++; /* w przeciwnym razie zmniejsz n */
        }
	return i;


}

void pwekt(double *v, int n)
{
        printf("[ ");
        while (n--) {
                printf("%g ", *v);
                v++;
        }
        printf("]");
}

int main()
{
        double          v[] = {-10, 0, 10, -20, 30, 1.1, -2.2, -3.3, 300.003, 1024.5};
        int             n = sizeof v / sizeof v[0];

        printf("Wektor: ");
        pwekt(v, n);
        printf(" (%d elementow)\n", n);
	int k ;
        k= usun_ujemne(v, n);
	pwekt(v,k);
        return 0;
}
