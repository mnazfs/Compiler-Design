%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
%}
%token NUMBER
%%
L:E'\n' {printf("Result = %d\n", $1);exit(0);}
;
E:E'+'T {$$ = $1 + $3;}
|T {$$ = $1;}
;
T:T'*'F {$$ = $1 * $3;}
|F {$$ = $1;}
;
F:NUMBER {$$ = $1;}
;
%%
void main()
{
	printf("Enter expression: ");
	yyparse();
}
yylex()
{
	char ch;
	ch = getchar();
	if(isdigit(ch)) {
		ungetc(ch, stdin);
		scanf("%d", &yylval);
		return NUMBER;
	} else
		return ch;
}
yyerror()
{
	printf("Error: Invalid expression\n");
	exit(0);
}
