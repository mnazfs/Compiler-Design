%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
%}
%token DIGIT LETTER
%%
L:A'\n' {printf("Valid\n");exit(0);}
;
A:LETTER B
|LETTER
;
B:LETTER B
|DIGIT B
|LETTER
|DIGIT
;
%%
void main()
{
	printf("Enter variable: ");
	yyparse();
}
yylex()
{
	char ch;
	ch = getchar();
	if(isalpha(ch))
		return LETTER;
	else if(isdigit(ch))
		return DIGIT;
	else
		return ch;
}
yyerror()
{
	printf("Invalid\n");
	exit(0);
}
