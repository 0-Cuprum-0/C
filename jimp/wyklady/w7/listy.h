#ifndef _LISTY_H_
#define _LISTY_H_ 

#include <stdlib.h>

typedef struct nd {
	double x;
	struct nd *nxt;
}  *list_t, node_t;

list_t insert( list_t l, double d ) ;

list_t append( list_t l, double d ) ;

list_t insort( list_t l, double d ) ;

list_t iinsort( list_t l, double d ) ;

#endif
