#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct elem {
	double x;
	struct elem * nast;
} elem_t;
typedef struct elem  *list_t;

list_t insert( list_t l, double nx );

list_t append( list_t l, double nx );

list_t append_no_rec( list_t l, double nx );

list_t insert_sort( list_t l, double nx );

list_t insert_sort_no_rec( list_t l, double nx );

void free_list( list_t l );

#endif
