#include <stdio.h>

int main( int argc, char *argv[] ) {
	FILE *in = argc > 1 ? fopen( argv[1], "r" ) : stdin;
	if( in == NULL ) {
		fprintf( stderr, "%s: nie mogem czytac %s\n", argv[0], argv[1] );
		return 1;
	}
	int c;
	int licznik['z'-'a'+1] = {0};
	while( (c=fgetc(in)) != EOF ) {
		if( c >= 'a' && c <= 'z' )
			licznik[c-'a']++;
	}

	for( int i= 0; i < 26; i++ ) {
		printf( "%c(%x)(%3d) - %d\n", 'a'+i, 'a'+i, 'a'+i, licznik[i] );
	}
	return 0;
}
