#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
	stack[++top] = x;
}

char pop()
{
	if(top == -1)
		return ' ';
	return stack[top--];
	
}

int priority(char x)
{
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 2;
	return 0;
}
void main()
{
	char input[25], postfix[25], *e, x;
	printf("Enter expression: ");
	scanf("%s", input);
	e = input;
	int i = 0;
	while(*e != '\0') {
		if(isalnum(*e))
			postfix[i++] = *e;
		else if(*e == '(')
			push(*e);
		else if(*e == ')') {
			while((x=pop()) != '(')
				postfix[i++] = x;
		} else {
			while(priority(stack[top]) >= priority(*e))
				postfix[i++] = pop();
			push(*e);
		}
		e++;
	}
	while(top != -1)
		postfix[i++] = pop();
	postfix[i] = '\0';
	
	i = 0;
	int sl = 1;
	while(postfix[i] != '\0') {
		char ch = postfix[i];
		if(isalpha(ch))
			push(ch);
		else {
			char ch2 = pop();
			char ch1 = pop();
			if(isalpha(ch1) && isalpha(ch2))
				printf("t%d = %c %c %c\n", sl, ch1, ch, ch2);
			else if(isalpha(ch1) && isdigit(ch2))
				printf("t%d = %c %c t%c\n", sl, ch1, ch, ch2);
			else if(isdigit(ch1) && isalpha(ch2))
				printf("t%d = t%c %c %c\n", sl, ch1, ch, ch2);
			else if(isdigit(ch1) && isdigit(ch2))
				printf("t%d = t%c %c t%c\n", sl, ch1, ch, ch2);
			push(sl + '0');
			sl++;
		}
		i++;
	}
}
