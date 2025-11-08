#ifndef _BST_H
#define _BST_H

#include <stdio.h>

typedef struct node {
	double x;
	struct node * l;
	struct node * r;
} node_t, *bst_t;

bst_t insert( bst_t t, double x );

void print_bst( bst_t t, int lev, FILE *out );

void print_incr( bst_t t, FILE *out );

void print_decr( bst_t t, FILE *out );

void free_bst( bst_t t );
#endif
