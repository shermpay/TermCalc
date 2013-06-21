/* Sherman Pay Jing Hao
   Monday, 17. June 2013
   Reverse Polish Calculator
   Handles + - * / % */

/* Cool beeans */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100
#define BUF_SIZE 100
#define NUMBER '0'

void push(double v);
void printS(void);
double pop(void);
double peek(void);
void clear(void);
double swap(void);

int getch(void);
void ungetch(int c);
int getop(char s[]);

int size = 0;
double stack[MAX];
char buf[BUF_SIZE];
int bufp = 0;


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
			clear();
			printf("\tcleared all entries\n");
			break;
		case 's':
			swap();
			printf("\tswapped the first 2 elements\n");
			break;
		case 'u':
			pop();
			printf("\tundid last move\n");
			break;
		case '\n':
			if (size > 0) 
				printf("\tlast element\n");
				printf("\t%.8g\n", peek());
			break;
		case 'h':
			printf("\n\'u\'\t undo last move\n");
			printf("\'s\'\t swap first two elements\n");
			printf("\'c\'\t clears all elements\n");
			printf("\'h\'\t prints the list of functions\n");
			printf("\'q\'\t quits the calculator\n\n");
			break;
		default:
			printf("\terror: unknown command %s\n", s);
			break;
		}
	}
	printf("Calculator end");
	return 0;
}

void push(double v)
{
	if (size < MAX) 
		stack[size++] = v;
	else
		printf("\terror: stack overflow\n");
}

void printS(void)
{
	int i;
	for (i = 0; i < size; i++) {
		printf("%g", stack[i]);
	}
	printf("\n");
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

void clear(void)
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
/* Gets the next character either from the buffer or the stdin */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* Stores the character in the buffer */
void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
	else
		printf("\terror: too many characters\n");
}

/* get the next operator or operand from either from stdin or buffer */
int getop(char s[])
{
	int i, c;
	
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.' && c != '-')
		return c;				/* not a number */
	
	i = 0;
	if (c == '-') {
		i++;
		c = getch();
		s[i] = c;
	}
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') 
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
