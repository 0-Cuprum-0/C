#include <stdio.h>

typedef struct {
	char *imie;
	char *nazwisko;
	int album;
} stud_t;

stud_t * find_stud( stud_t grupa[], int n, int album ) {
	for( int i= 0; i < n; i++ )
		if( grupa[i].album == album )
			return grupa+i;
	return NULL;
}

#include <stdlib.h> // atoi

int main( int argc, char **argv ) {
	stud_t g1[] = 	{ 
				{ "Anna", "Kowalska", 12345 },
				{ "Jan", "Kowalski", 22345 },
				{ "Adam", "Nowak", 32345 },
				{ "Zofia", "Nowak", 42345 },
				{ "Zenon", "Ostatni", 52345 }
			};
	int n = sizeof g1 / sizeof g1[0];

	stud_t *x = NULL;

	if( argc > 1 && (x= find_stud( g1, n, atoi(argv[1]) )) != NULL )
		printf( "%d %s %s\n", x->album, x->imie, x->nazwisko );
	else {
		printf( "Dostępne nr albumu: ");
		for( int i= 0; i < n; i++ )
			printf( "%d ", g1[i].album );
		printf( "\n" );
	}
	return 0;
}
