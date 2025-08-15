%{
#include<math.h>
int flag = 0;
int a;
%}
DIGIT [0-9]
WS [ \t]
%%
{WS}+ {}
"+" {flag = 1;}
"-" {flag = 2;}
"*" {flag = 3;}
"/" {flag = 4;}
"^" {flag = 5;}
{DIGIT}+ {if(flag == 0) 
		a = atoi(yytext);
	   else if(flag ==1)
	   	a += atoi(yytext);
	   else if(flag ==2)
	   	a -= atoi(yytext);
	   else if(flag ==3)
	   	a *= atoi(yytext);
	   else if(flag ==4)
	   	a /= atoi(yytext);
	   else if(flag ==5)
	   	a = pow(a, atoi(yytext));}
"\n" {printf("Result = %d\n", a);exit(0);}
. {printf("Invalid characters: %s\n", yytext);exit(0);}
%%
void main()
{
	printf("Enter expression: ");
	yyin = stdin;
	yylex();
}
int yywrap()
{
	return 1;
}
