#include <stdlib.h>
#include <stdio.h>
#include "fun_stack.h"

int main(){
//list_t query;
int level = 1;
char *name = "hatsune_miku_owns_the_world";
printf("Stos jeszcze pusty, sprobujemy znaleść ostatni->num_brac(top_of_funstack()):\n ");

int last_num_brac=top_of_funstack(); 
//printf("%d", last_num_brac); //////!!!!!!!!!!!!
printf("Srobujemy dodac nowy element z num_brac=1 i name_func =hatsune_miku_owns_the_worldput_on_fun_stack():\n");
put_on_fun_stack(level, name );
printf("Jaki num_brak ma ostatni element teraz(top_of_funstack())?\n");
last_num_brac=top_of_funstack();
printf("%d\n", last_num_brac);

printf("Teraz usuwamy ostatni element i piszemy go num_brac (get_from_fun_stack()):\n");
char *last_name =get_from_fun_stack();
for (int i =0; last_name[i]= '\0'; i++){
    printf("%c", last_name[i]);
    
    }
printf("\n");
printf("Jaki num_brak ma ostatni element teraz(top_of_funstack())?\n");
last_num_brac= top_of_funstack();  
// printf("%d", last_num_brac);/////////!!!!!!!!!!!!!!!!!!!!!!
}