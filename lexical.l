%{
#include<stdio.h>
FILE *fp;
int line=1;
int slno=1;
%}
DIGIT [0-9]
ALPHA [a-zA-Z]
WS [ \t]
%%
{WS}+ {}
"\n" {line++;}
";" {fprintf(fp,"%d\t\t;\t\tSemicolon\t\t%d\n",slno,line); slno++;}
"+"|"-"|"*"|"/" {fprintf(fp,"%d\t\t%s\t\tArithmetic_op\t\t%d\n",slno,yytext,line); slno++;}
"{"|"["|"(" {fprintf(fp,"%d\t\t%s\t\tOpening Bracket\t\t%d\n",slno,yytext,line); slno++;}
"}"|"]"|")" {fprintf(fp,"%d\t\t%s\t\tClosing Bracket\t\t%d\n",slno,yytext,line); slno++;}
"<"|">"|"<="|">="|"!"|"!="|"==" {fprintf(fp,"%d\t\t%s\t\tRelational_op\t\t%d\n",slno,yytext,line); slno++;}
"=" {fprintf(fp,"%d\t\t%s\t\tAssign_op\t\t%d\n",slno,yytext,line); slno++;}
"#"|"&"|"."|"," {fprintf(fp,"%d\t\t%s\t\tSpecial Char\t\t%d\n",slno,yytext,line); slno++;}
"void"|"main"|"if"|"else"|"for"|"while"|"do"|"int"|"char"|"float"|"double"|"printf"|"include"|"stdio.h"  {fprintf(fp,"%d\t\t%s\t\tKeyword   \t\t%d\n",slno,yytext,line); slno++;}
{ALPHA}+({ALPHA}|{DIGIT})* {fprintf(fp,"%d\t\t%s\t\tIdentifier\t\t%d\n",slno,yytext,line); slno++;}
{DIGIT}+"."{DIGIT}+ {fprintf(fp,"%d\t\t%s\t\tFloat_Point\t\t%d\n",slno,yytext,line); slno++;}
. {fprintf(fp,"%d\t\t%s\t\tUnrecognised\t\t%d\n",slno,yytext,line); slno++;}
%%
void main(int argc[], char* argv[])
{
	yyin=fopen(argv[1],"r");
	fp=fopen(argv[2],"w");
	fprintf(fp, "Sl No\t\tLexeme\t\tToken   \t\tLine No\n------------------------------------------------------------------\n");
	yylex();
	printf("Lexical Analysis is done on %s and output is written into %s.txt\n", argv[1], argv[2]);
}
int yywrap()
{
	return 1;
}
