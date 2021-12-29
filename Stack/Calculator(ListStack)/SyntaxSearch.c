// ���� ǥ��� ��ȯ �� ���� �˻� 

#include <stdio.h>		// ����� ����  
#include <string.h>		// ���ڿ� ���� 
#include <ctype.h>		// ��������, �������� 

#include "ListStack.h"
#include "Calculator.h"

int SyntaxSearch(char exp[]) {
	Stack stack;
	S_Init(&stack);
	
	int i, count;
	char opt, bracket, check;
	
	for(i = 0; exp[i] != '\0'; i++) {
		// �����̸� �ѱ� 
		if(exp[i] == ' ') continue;
		
		check = exp[i];
		
		switch(check) {
			// ������ ���� ���� �������� ��� 
			case '+': case '-': case '*': case '/':
				opt = exp[i + 1];
				if(opt == '+' || opt == '-' || opt == '*' || opt == '/') {
					printf(">> ' %c ' ������ ����!\n", opt);
					return -1;
				} else if(!isdigit(opt) && opt != '(' && opt != '{' && opt != '[' && opt != ' ') {
				// ������ ���� ���� ��ȣ�� �ƴϸ�, ���ڰ� �ƴϸ�, ������ �ƴ� ��� 
					printf(">> ' %c ' ������ ����!\n", check);
					return -1;
				}
				break;
			
			// ���� ��ȣ�� ��� ���ÿ� ���� 
			case '(': case '{': case '[':
				S_Push(&stack, check);
				break;
			
			// �ݴ� ��ȣ�� ��� 
			case ')': case '}': case ']':
				bracket = exp[i];
				
				// ������ ���� ���� �ʴ� ���  
				if(S_Empty(&stack)) {
					printf(">> ' %c ' ���� ����!\n", bracket);
					return -1;
				} else {
				// ������ ���� ������ ��ȣ�� �ٸ� ��� 
					if(bracket == ')') {
						if(S_Pop(&stack) != '(') {
							printf(">> ' %c ' ���� ����!\n", bracket);
							return -1;
						}
					} else if(bracket == '}') {
						if(S_Pop(&stack) != '{') {
							printf(">> ' %c ' ���� ����!\n", bracket);
							return -1;
						}
					} else {
						if(S_Pop(&stack) != '[') {
							printf(">> ' %c ' ���� ����!\n", bracket);
							return -1;
						}
					}
				}
				break;
			
			default:
				// ���ڰ� �ƴ� ��� , ������ ��� 
				if(!isdigit(check)) {
					printf(">> ���ڸ� �Է����ּ��� !\n");
					return -1;
				} else {
					bracket = exp[i + 1];
					
					// ���� ������ �����ڰ� �ƴ� ���� ��ȣ�� ��� 
					if(bracket == '(' || bracket == '{' || bracket == '[' ) {
						printf(">> ��ȣ ���� ����!\n");
						return -1;
					}
					
					count++;
				}
				break;
		}
	}
	
	// �ϳ��� �Էµ��� �ʾҰų�, �ϳ��� �Էµ� ��� 
	if(!count || count == 1) {
		printf(">> �߸��� �����Դϴ�.\n");
		return -1;
	}
	
	// ��� ���� ���� ��� �۵� 
	while(!S_Empty(&stack)) {
		// ���� ��ȣ�� ���� ��� 
		opt = S_Pop(&stack);
		if(opt == '(' || opt == '{' || opt == '[') {
			printf(">> ' %c ' ���� ����!\n", opt);
			return -1;
		}
	}
	
	return 0;
}
