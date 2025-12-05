#include <stdio.h>
#include <stdlib.h>

#include "bibl.h"               /* dzieki temu kompilator moze sprawdzic, czy
                                 * dobrze wywolujemy funkcje z naszej
                                 * biblioteki */

int
main(int argc, char *argv[])
{
        double           w_1[10];
        double           w_2[10];
        int             n1;
        int             n2;
        int             i;

        FILE           *we = argc > 1 ? fopen(argv[1], "r") : stdin; 
        FILE		*wy  = fopen("wyjscie.txt", "w+");                                                                
                                                                         
                                                                       
                                                                 

        if (we == NULL) {       /* stdin != NULL, a wiec to mozliwe tylko,
                                 * gdy argv[1] zawiera cos, co nie jest nazwa
                                 * istniejacego pliku */
                fprintf(stderr, "Plik wejsciowy %s nie istnieje!\n", argv[1]);
                exit(1);
        }
//	printf("1");
        n1 = read(we, w_1, 10);   /* czytamy z wejscia wektor i pakujemy go
                                 * do w_1 */
	
//	printf("2");

        if (n1 > 0) {
		fprintf(wy,"__________1_wector__________\n");
                fprintf(wy,"Wczytano %i-elementowy wektor:\n( ", n1);
                for (i = 0; i < n1; i++)
                        fprintf(wy,"%f ", w_1[i]);
                fprintf(wy,")\n");
        } else {
                fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n1);
                return 1;
        }
	
	
//	printf("3");//
	double l2_1 = L2(w_1,n1);
        fprintf(wy,"Norma L2 wczytanego wektora = %f\n", l2_1);

	fprintf(wy,"norma max: %lf\n", norm_max(w_1,n1));
	fprintf(wy,"Nomalizacja:");
	normal(w_1,n1,l2_1, wy);
        n2 = read(we, w_2, 10);   /* czytamy z wejscia wektor i pakujemy go do w_2 */

//	printf("4");
        if (n2 > 0) {
	      fprintf(wy,"__________2_wector__________\n");

              fprintf(wy,"Wczytano %i-elementowy wektor:\n( ", n2);
              for (i = 0; i < n2; i++)
                      fprintf(wy,"%f ", w_2[i]);
              fprintf(wy,")\n");
      } else {
              fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n2);
              return 1;
      }

	fprintf(wy,"norma max: %lf\n", norm_max(w_2,n2));
//	printf("5");
//	double arr[3]={1,2,3};

//	printf("6");//
	double l2_2 = L2(w_2, n2);
        fprintf(wy,"Norma L2 wczytanego wektora = %f\n", l2_2);
	fprintf(wy,"Nomalizacja:");
	normal(w_2,n2,l2_2 ,wy);
        if (n1 == n2 ) {
		fprintf(wy,"====================\n");

                fprintf(wy,"Iloczyn skalarny wczytanych wektorow = %f\n", dot_product(w_1, w_2, n1));
		fprintf(wy,"Summa: ");
		summa(w_1, w_2, n1, wy);
        } else {
                fprintf(wy,"Wczytane wektory maja rozna dlugosci i nie mozna ich pomnozyc przez siebie\n" );
        }
	fclose(wy);
        return 0;


}
