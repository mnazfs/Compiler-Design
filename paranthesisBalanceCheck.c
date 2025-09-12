#include<stdio.h>

void main(int argc, char* argv[]) {
	FILE *fp;
	fp = fopen(argv[1], "r");
	char ch, ch1, stack[100];
	int top = -1, line = 1;
	while((ch = fgetc(fp)) != EOF) {
		switch(ch) {
			case '(':
			case '{':
			case '[': 
				stack[++top] = ch;
				break;
			case '\n': 
				line++;
				break;
			case ')': 
				if(top == -1)
					printf("Open bracket missing for %c at line %d\n", ch, line);
				else {
					ch1 = stack[top--];
					if(ch1 != '(') {
						printf("Paranthesis mismatch %c %c at line %d\n", ch1, ch, line);
						stack[++top] = ch1;
					}
				}
				break;
			case '}': 
				if(top == -1)
					printf("Open bracket missing for %c at line %d\n", ch, line);
				else {
					ch1 = stack[top--];
					if(ch1 != '{') {
						printf("Paranthesis mismatch %c %c at line %d\n", ch1, ch, line);
						stack[++top] = ch1;
					}
				}
				break;
			case ']': 
				if(top == -1)
					printf("Open bracket missing for %c at line %d\n", ch, line);
				else {
					ch1 = stack[top--];
					if(ch1 != '[') {
						printf("Paranthesis mismatch %c %c at line %d\n", ch1, ch, line);
						stack[++top] = ch1;
					}
				}
				break;
			default:
		}
	}
	if(top != -1)
		while(top != -1) {
			ch = stack[top--];
			printf("Closing bracket missing for %c at line %d\n", ch, line);
		}
	else {
		printf("Paranthesis is balanced\n");
	}
	fclose(fp);
}
