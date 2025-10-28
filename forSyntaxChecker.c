#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return 1;
	}
	
	char ch;
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		printf("Error opening file\n");
		return 1;
	}
	
	char lexeme[100][50];
	int i = 0, j = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == ' ' || ch == '\t' || ch == '\n')
		{
			continue;
		}
		else if(isalnum(ch))
		{
			do {
				lexeme[i][j] = ch;
				j++;
				ch = fgetc(fp);
			} while(isalnum(ch));
			
			lexeme[i][j] = '\0';
			ungetc(ch, fp);
			i++;
			j = 0;
		}
		else
		{
			lexeme[i][j] = ch;
			j++;
			lexeme[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	
	fclose(fp);
	
	int count = i;
	printf("Simple lexeme separation:\n");
	for(i = 0; i < count; i++)
	{
		printf("%s\n", lexeme[i]);
	}
	
	for(i = 0; i < count; i++)
	{
		if(strcmp(lexeme[i], "for") == 0)
		{
			i++;
			if(i < count && strcmp(lexeme[i], "(") == 0)
			{
				int semicolon_count = 0;
				i++;
				
				while(i < count && strcmp(lexeme[i], ")") != 0)
				{
					if(strcmp(lexeme[i], ";") == 0)
					{
						semicolon_count++;
					}
					i++;
				}
				printf("RESULT\n");
				if(i >= count)
				{
					printf("Missing ')'\n");
					return 1;
				}
				
				if(semicolon_count == 2)
				{
					printf("Syntax correct\n");
				}
				else if(semicolon_count < 2)
				{
					printf("Missing ';' \n");
				}
				else
				{
					printf("Too many ';'\n");
				}
			}
			else
			{
				printf("Missing '(' after for\n");
			}
		}
	}
	
	return 0;
}