#include <stdio.h>
#include <stdlib.h>

void losowe( char * s ) {
	int n = rand() % 20;
	s[0] = 'A' + rand() % 26;
	for( int i= 1; i < n; i++ )
		s[i] = 'a' + rand() % 26;
	s[n] = '\0';
}

int main( int argc, char **argv ) {
	int n = argc > 1 ? atoi(argv[1]) : 30;

	char imie[32], nazwisko[32];

	for( int i = 0; i < n; i++ ) {
		losowe( imie);
		losowe( nazwisko);
		printf( "%s %s %d\n", imie, nazwisko, rand() % 100 );
	}

	return 0;
}
