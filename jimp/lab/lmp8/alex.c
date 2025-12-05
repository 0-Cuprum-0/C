#include "alex.h"
#include <stdlib.h>

#include <ctype.h>
#include <string.h>

typedef struct nd {
  int num_brac;
  char name_func[100];
  struct nd *nxt;
}  *list_t, node_t;

static list_t stackTop = NULL;

static int  ln= 0;
static char ident[256];
static FILE *ci= NULL;



void    alex_init4file( FILE *in ) {
   ln= 0;
   ci= in;
}

lexem_t alex_nextLexem( void ) {
  int c;
  while( (c= fgetc(ci)) != EOF ) {
    if( isspace( c ) )
                        continue;
                else if( c == '\n' )
                        ln++;
    else if( c == '(' )
                        return OPEPAR;
    else if( c == ')' )
      return CLOPAR;
    else if( c == '{' )
                        return OPEBRA;
    else if( c == '}' )
                        return CLOBRA;
    else if( isalpha( c ) ) {
      int i= 1;
      ident[0] = c;
      while( isalnum( c= fgetc(ci) ) )
                                ident[i++] = c;
                        ident[i] = '\0';
      //return isKeyword(ident) ? IDENT : OTHER;
                } else if( c == '"' ) {
      /* Uwaga: tu trzeba jeszcze poprawic obsluge nowej linii w trakcie napisu
         i \\ w napisie 
      */
      int cp = c;
                        while( (c= fgetc(ci)) != EOF && c != '"' && cp == '\\' ) {
                                cp = c;
      }
      return c==EOF ? EOFILE : OTHER; 
    } else if( c == '/' ) {
      /* moze byc komentarz */
                } if( isdigit( c ) || c == '.' ) {
      /* liczba */
                } else {
      return OTHER;
                }
        }       
  return EOFILE;
}

char *  alex_ident( void ) {
   return ident;
}

int     alex_getLN() {
        return ln;
}

//STOS

int top_of_funstack( void ){
  if (stackTop!=NULL){
    return stackTop-> num_brac;
    }else{
      printf("Stos pusty!!!\n");
    }

};  // zwraca par_level - "zagłębienie nawiasowe" przechowywane na szczycie
void put_on_fun_stack( int par_level, char *funame ){

		list_t nowy = malloc( sizeof *nowy );
		nowy->num_brac = par_level;
    strcpy(nowy->name_func, funame);
		nowy->nxt = stackTop;
    stackTop=nowy;
    printf("Zrobilam nowy element!!! z num_brac =  %d i name_func = ", par_level);
    while ( *funame != '\0'){
      printf("%c", *funame++);
    }
    printf("\n");
	


}; // odkłada na stos parę (funame,par_level)

char *get_from_fun_stack( void ){
  list_t top = stackTop;
  stackTop = stackTop->nxt;
  char *old_name = strdup(top->name_func);
  int old_num = top->num_brac;
  printf("Usunelam element!!! z num_brac =  %d i name_func = ", old_num);
    while ( *old_name != '\0'){
      printf("%c", *old_name++);
    }
    printf("\n");
  free(top);
  return old_name;
  


}; // usuwa z wierzchołka parę (funame,par_level), zwraca zdjętą funame

