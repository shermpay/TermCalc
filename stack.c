/* Sherman Pay Jing Hao
   Thursday, 30. January 2014
*/

#include <stdio.h>
#include "getch.h"

int size = 0;
double stack[MAX];

void push(double v)
{
    if (size < MAX) 
	stack[size++] = v;
    else
	printf("\terror: stack overflow\n");
}

void print(void)
{
    int i;
    if (size > 0) {
	printf("Current stack: [%g", stack[0]);
	for (i = 1; i < size; i++) {
	    printf(", %g", stack[i]);
	}
	printf("]\n");
    } else {
	printf("Stack Empty!\n");
    }
}

double pop(void)
{
    if (size > 0) 
	return stack[--size];
    else {
	printf("\terror: stack empty\n");
	return 0.0;
    }
}

double peek(void)
{
    if (size > 0) 
	return stack[size - 1];
    else {
	printf("\terror: stack empty\n");
	return 0.0;
    }
}

void empty(void)
{
    int i;
    for (i = 0; i < size; i++) {
	stack[i] = '\0';
    }
    size = 0;
}

/* Swaps the first 2 elements and returns the 2nd element */
double swap(void)
{
    double top = pop();
    double bot = pop();
    push(top);
    push(bot);
	
    return bot;
}

int get_size(void)
{
    return size;
}
