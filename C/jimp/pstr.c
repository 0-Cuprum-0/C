#include <stdio.h>  // wiadomo po co
#include <stdlib.h> // qsort
#include <string.h> // strstr

#define BUFSIZE 8192    // zakładamy, że linie będą krótsze niż 8kB

int
main( int argc, char **argv ) {
  int ile_linii;
	char buf[BUFSIZE];
	FILE *in= argc > 1 ? fopen( argv[1], "r" ) : stdin;

	int tryb;
	if (argc>2){
		tryb= atoi(argv[2]);
	
	}else{
		printf("Tryb nie zostal wybrany, dlatego =0");
		int tryb = 0;
	}
	
	char *str= argc > 3 ? argv[3] : NULL;

	

	if( str == NULL ) {
		fprintf( stderr, "%s: błąd: proszę podac napis do wyszukiwania\n", argv[0] );
		return EXIT_FAILURE;
	}

	if( in == NULL ) {
		fprintf( stderr, "%s: błąd: nie mogę czytać pliku %s\n", argv[0], argv[1] );
		return EXIT_FAILURE;
	}
	if (tryb == 0){
		printf("TRYB 0\n");
		ile_linii= 0;
		while( fgets( buf, BUFSIZE, in ) != NULL ) {
			ile_linii++;
			if( strstr( buf, str ) != NULL ){
				printf("%d. ", ile_linii);

				printf( "%s\n", buf );
			}
		}
	}
	if(tryb == 1){
		printf("TRYB 1\n");
                ile_linii= 0;
                while( fgets( buf, BUFSIZE, in ) != NULL ) {
                        ile_linii++;
			buf[strcspn(buf, "\n")]='\0';
			if (strcmp(buf,str)==0){
				printf("%d. ", ile_linii);

                                printf( "%s\n", buf );
			}
		}	
	
	
	}else{
		printf("Tylko 1 lub 0\n");
	}
	return EXIT_SUCCESS;
}
