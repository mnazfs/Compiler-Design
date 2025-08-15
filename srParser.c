#include<stdio.h>

char input[15], stack[15];
int ind = 0, sl = 1, top = 0;

void reduce()
{
	for(int j = 0; j < top; ++j)
		if(stack[j] == 'i') {
			stack[j] = 'E';
			printf("%d\t$%s\t%s$\t\tReduce E -> i\n", sl, stack, input);
			sl++;
		}
	for(int j = 0; j < top; ++j)
		if(stack[j] == '(' && stack[j + 1] == 'E' && stack[j + 2] == ')') {
			stack[j] = 'E';
			stack[j + 1] = '\0';
			top -= 2;
			printf("%d\t$%s\t%s$\t\tReduce E -> (E)\n", sl, stack, input);
			sl++;
		}
	for(int j = 0; j < top; ++j)
		if(stack[j] == 'E' && stack[j + 1] == '+' && stack[j + 2] == 'E') {
			stack[j] = 'E';
			stack[j + 1] = '\0';
			top -= 2;
			printf("%d\t$%s\t%s$\t\tReduce E -> E+E\n", sl, stack, input);
			sl++;
		}
	for(int j = 0; j < top; ++j)
		if(stack[j] == 'E' && stack[j + 1] == '*' && stack[j + 2] == 'E') {
			stack[j] = 'E';
			stack[j + 1] = '\0';
			top -= 2;
			printf("%d\t$%s\t%s$\t\tReduce E -> E*E\n", sl, stack, input);
			sl++;
		}
}

void main()
{
	printf("Enter input: ");
	scanf("%s", input);
	
	printf("\nSl No\tStack\tInput     \tAction\n------------------------------------------------\n");
	printf("%d\t$%s\t%s$\t\t-\n", sl, stack, input);
	sl++;
	
	while(input[ind] != '\0') {
		stack[top++] = input[ind];
		stack[top] = '\0';
		input[ind++] = ' ';
		printf("%d\t$%s\t%s$\t\tShift %c\n", sl, stack, input, stack[top - 1]);
		sl++;
		reduce();
	}
	
	if(stack[0] == 'E' && stack[1] == '\0')
		printf("\nInput accepted\n");
	else
		printf("\nInput rejected\n");
}
