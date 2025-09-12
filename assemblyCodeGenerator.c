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
	
	int add;
	printf("Enter starting address: ");
	scanf("%d", &add);
	i = 0;
	printf("\n");
	while(postfix[i] != '\0') {
		if(isalpha(postfix[i])) {
			printf("%d: MOV A, %c\n", add++, postfix[i]);
			printf("%d: PUSH A\n", add++);
		} else {
			printf("%d: POP B\n", add++);
			printf("%d: POP A\n", add++);
			switch(postfix[i]) {
				case '+': printf("%d: ADD B\n", add++);
					   break;
				case '*': printf("%d: MUL B\n", add++);
					   break;
				case '-': printf("%d: SUB B\n", add++);
					   break;
				case '/': printf("%d: DIV B\n", add++);
					   break;
			}
			printf("%d: PUSH A\n", add++);
		}
		i++;
	}
	printf("%d: POP A\n", add++);
	printf("%d: HLT\n", add);
}
