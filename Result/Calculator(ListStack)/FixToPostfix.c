// 후위 표기법 변환 소스 파일 

#include <stdio.h>		// 입출력 관련 
#include <stdlib.h>		// 동적할당 관련 
#include <string.h>		// 문자열 관련 
#include <ctype.h>		// 숫자인지, 문자인지 

#include "ListStack.h"
#include "Calculator.h"

// 우선순위 
int OptPrec(char opt) {
	switch(opt) {
		case '*': case '/':				return 5;
		case '+': case '-':				return 3;
		case '(': case '{': case '[':	return 1;
	}
	
	return -1;
}

// 후위표기법 
void ConvToPostfix(char exp[]) {
	Stack stack;
	S_Init(&stack);
	
	int expLen = strlen(exp);
	char * ConvExp = (char*)malloc(expLen * 2);
	int i, idx = 0, popOp;

	for(i = 0; exp[i] != '\0'; i++) {
		if(exp[i] == ' ') continue;
		
		if(isdigit(exp[i])) {
		// 문자가 숫자인지 아닌지 확인 ( 0 ~ 9 ) 
			// 숫자라면 문자 배열에 투입 
			ConvExp[idx++] = exp[i];
		} else {
			// 숫자가 아니라면 스택에 투입 
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
					// 값이 비어있지 않고, 기존 값이 현재 값보다 크거나 같으면 
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
	
	// 스택에 있는 연산자 모두 배열 삽입 
	while(!S_Empty(&stack)) {
		ConvExp[idx++] = ' ';
		ConvExp[idx++] = S_Pop(&stack);
	}
	
	// 문자열 끝맺음 
	ConvExp[idx] = '\0';
	
	strcpy(exp, ConvExp);
	free(ConvExp);
}
