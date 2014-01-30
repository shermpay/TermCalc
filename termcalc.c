/* Sherman Pay Jing Hao
   Monday, 17. June 2013
   Reverse Polish Calculator
   Handles + - * / % */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "getch.h"

#define MAX 100
#define NUMBER '0'

int main(void)
{
    int type;
    double op;
    char s[MAX];

    /* Prints the intro message */
    printf("Reverse polish calculator:\n");
    printf("Allows + - * / and %% \n");
    printf("\'h\' to print a list of commmands and \'q\' to quit\n\n");

    while ((type = getop(s)) != 'q') {
	switch (type) {
	    case NUMBER:
		push(atof(s));
		break;
	    case '+':
		push(pop() + pop());
		break;
	    case '-':
		op = pop();
		push(pop() - op);
		break;
	    case '*':
		push(pop() * pop());
		break;
	    case '/':
		op = pop();
		if (op != 0.0) 
		    push(pop() / op);
		else {
		    pop();
		    printf("\terror: zero division\n");
		}
		break;
	    case '%':
		op = pop();
		push((int)pop() % (int)op);
		break;
	    case 'c':
		empty();
		printf("\temptied all entries\n");
		break;
	    case 's':
		swap();
		printf("\tswapped the first 2 elements\n");
		break;
	    case 'u':
		pop();
		printf("\tundid last move\n");
		break;

	    case 'p':
		print();
		break;
	    case '\n':
		if (get_size() > 0) 
		    printf("\tlast element: ");
		printf("\t%.8g\n", peek());
		break;
	    case 'h':
		printf("\n'p'\t prints elements in the stack");
		printf("\n\'u\'\t undo last move\n");
		printf("\'s\'\t swap first two elements\n");
		printf("\'c\'\t emptys all elements\n");
		printf("\'h\'\t prints the list of functions\n");
		printf("\'q\'\t quits the calculator\n\n");
		break;
	    default:
		printf("\terror: unknown command %s\n", s);
		break;
	}
    }
    printf("\nCalculator end\n");
    printf("---------- \n");
    return 0;
}
