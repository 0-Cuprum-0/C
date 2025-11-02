#include <stdio.h>

int main( int argc, char *argv[] ) {
	int c;
	int licznik['z'-'a'+1] = {0};
	while( (c=getchar()) != EOF ) {
		if( c >= 'a' && c <= 'z' )
			licznik[c-'a']++;
	}

	for( int i= 0; i < 26; i++ ) {
		printf( "%c(%x)(%3d) - %d\n", 'a'+i, 'a'+i, 'a'+i, licznik[i] );
	}
	return 0;
}
