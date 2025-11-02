#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


// DEFINE STATES
 
typedef enum state {
	Q0, Q1, Q2, Q3
}State; 
State accept = Q2;
State start = Q0;

int automata(State acc, State st, int input);

int main (){
	//INTRO
	//
	printf("WELCOME TO AUTOMATA SIMULATOR\n");
	printf("Table for this automata:\n");
	printf("State | Input|\n");

	printf("      | 0 | 1 |\n");
	printf(" q_0  |q_1|q_2|\n");
	printf(" q_1  |q_3|q_1|\n");
	printf(" q_2  |q_0|q_3|\n");
	printf(" q_3  |q_1|q_2|\n");
	printf("It's language is {0 ; 1}\n");
	printf("Please, enter your input symbols without spaces in one line: \n");
	
	//WORK ON INPUT
	//
	int sym[100] = {};
	int c;

	while ((c= getchar()) != EOF){
		if (isspace(c)){
			continue;
		}
		if (c == '1' || c == '0')
			sym +=c - '0';
		else{ 
			printf("Only 0 and 1 !\n");
			return 1;
		}
	}


	automata( accept, start, sym);



	
}
int automata(State acc, State st, int input){
        State current = st;
        printf("%d", current);
	int length = sizeof(input)/ sizeof(input[0]);
	printf("%d", length);
	for(int i = 0; i < length;i++)
		switch (current) {
			case 0:
				if(input[i] == 0){
					printf("q0->q1");
					current = Q1;
					printf("%d",current);
				}else{
					printf("q0->q2");
					current = Q2;
					printf("%d",current);
				}
	



	}
        

                
}
