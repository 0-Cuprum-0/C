#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *imie;
	char *nazwisko;
	int punkty;
} student_t;

int cmpin( const void *a, const void *b ) {
	student_t sa = *(student_t*)a;
	student_t sb = *(student_t*)b;
	return sa.punkty - sb.punkty;
}

int sorted( char *t, int n, size_t s, int (*f)(const void *, const void * ) ) {
	for( int i= 1; i < n; i++ )
		if( f( t+(i-1)*s, t+i*s) > 0 )
			return 0;
	return 1;
}

int podziel( char *t, int p, int k, size_t s, int (*f)(const void *, const void *) ) {
	char *tmp = malloc( s );
	int i= p+1;
	int j= k;
	while( i < j ) {
		while( i < j && f( t+i*s, t+p*s ) <= 0 )
			i++;
		while( i < j && f( t+j*s, t+p*s) > 0 )
			j--;
		if( i != j ) {
			memcpy( tmp, t+i*s, s );
			memcpy( t+i*s, t+j*s, s );
		       	memcpy( t+j*s, tmp, s );
		}
	}
	if( f( t+i*s, t+p*s) > 0 )
		i--;
	memcpy( tmp, t+i*s, s );
	memcpy( t+i*s, t+p*s, s );
	memcpy( t+p*s, tmp, s );
	free(tmp);
	return i;
}

void qsrect( char *t, int p, int k, size_t s, int (*f)(const void *, const void *) ) {
	if( k > p ) {
		int m = podziel( t, p, k, s, f );
		qsrect( t, p, m-1, s, f );
		qsrect( t, m+1, k, s, f );
	}
}

void kusort( char *t, int n, size_t s, int (*f)(const void *, const void *) ) {
	qsrect( t, 0, n-1, s, f );
}

int main(int argc, char **argv) {
	int (*f)( const void*, const void * ) = cmpin;
	char buf[1024]; // linia moÅe miec max 1023 znaki (z \n)
	student_t grupa[100]; // max 100 studentow
	int n = 0;
	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
	if( in == NULL )
		return 1;
	while( fgets(buf, 1024, in) != NULL ) {
		char imie[1024], nazwisko[1024];
		int pkt;
		if( sscanf( buf, "%s %s %d", imie, nazwisko, &pkt ) != 3 ) {
			fprintf( stderr, "%s: nie podoba mi siem: \"%s\" !\n", argv[0], buf );
		} else {
			grupa[n].punkty = pkt;
			grupa[n].imie = malloc( strlen(imie)+1 );
			strcpy( grupa[n].imie, imie );
			grupa[n].nazwisko = malloc( strlen(nazwisko)+1 );
			strcpy( grupa[n].nazwisko, nazwisko );
			n++;
		}
	}
	for( int i= 0; i < n; i++ )
		printf( "%s %s %d\n", grupa[i].imie, grupa[i].nazwisko, grupa[i].punkty );
	kusort( (char*)grupa, n, sizeof grupa[0], f );
	printf( sorted( (char*)grupa, n, sizeof grupa[0], f ) ? "posortowana\n" : "nieposortowana\n" );
	if( n <= 20 ) {
		for( int i= 0; i < n; i++ )
			printf( "%s\n", grupa[i].nazwisko );
	}
	return 0;
}
