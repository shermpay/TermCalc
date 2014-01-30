/* Sherman Pay Jing Hao
   Thursday, 30. January 2014*/

/* Gets the next character either from the buffer or stdin */
#include <stdio.h>
#include <ctype.h>
#include "getch.h"

char buf[BUF_SIZE];
int bufp = 0;

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
