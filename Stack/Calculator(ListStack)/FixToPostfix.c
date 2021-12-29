// ���� ǥ��� ��ȯ �ҽ� ���� 

#include <stdio.h>		// ����� ���� 
#include <stdlib.h>		// �����Ҵ� ���� 
#include <string.h>		// ���ڿ� ���� 
#include <ctype.h>		// ��������, �������� 

#include "ListStack.h"
#include "Calculator.h"

// �켱���� 
int OptPrec(char opt) {
	switch(opt) {
		case '*': case '/':				return 5;
		case '+': case '-':				return 3;
		case '(': case '{': case '[':	return 1;
	}
	
	return -1;
}

// ����ǥ��� 
void ConvToPostfix(char exp[]) {
	Stack stack;
	S_Init(&stack);
	
	int expLen = strlen(exp);
	char * ConvExp = (char*)malloc(expLen * 2);
	int i, idx = 0, popOp;

	for(i = 0; exp[i] != '\0'; i++) {
		if(exp[i] == ' ') continue;
		
		if(isdigit(exp[i])) {
		// ���ڰ� �������� �ƴ��� Ȯ�� ( 0 ~ 9 ) 
			// ���ڶ�� ���� �迭�� ���� 
			ConvExp[idx++] = exp[i];
		} else {
			// ���ڰ� �ƴ϶�� ���ÿ� ���� 
			switch(exp[i]) {
				case '(': case '{': case '[':
					S_Push(&stack, exp[i]);
					break;
				case ')': case '}': case ']':
					while(1) {
						popOp = S_Pop(&stack);
						
						if(popOp == '(' || popOp == '{' || popOp == '[') {
							break;
						}
						
						ConvExp[idx++] = ' ';
						ConvExp[idx++] = popOp;
					}
					break;
				case '+': case '-': case '*': case '/':
					// ���� ������� �ʰ�, ���� ���� ���� ������ ũ�ų� ������ 
					while(!S_Empty(&stack) && OptPrec(exp[i]) <= OptPrec(S_Peek(&stack))) {
						ConvExp[idx++] = ' ';
						ConvExp[idx++] = S_Pop(&stack);
					}
					ConvExp[idx++] = ' ';
					S_Push(&stack, exp[i]);
					break;
			}
		}
		
	}
	
	// ���ÿ� �ִ� ������ ��� �迭 ���� 
	while(!S_Empty(&stack)) {
		ConvExp[idx++] = ' ';
		ConvExp[idx++] = S_Pop(&stack);
	}
	
	// ���ڿ� ������ 
	ConvExp[idx] = '\0';
	
	strcpy(exp, ConvExp);
	free(ConvExp);
}
