// 후위 표기법 변환 전 문법 검사 

#include <stdio.h>		// 입출력 관련  
#include <string.h>		// 문자열 관련 
#include <ctype.h>		// 숫자인지, 문자인지 

#include "ListStack.h"
#include "Calculator.h"

int SyntaxSearch(char exp[]) {
	Stack stack;
	S_Init(&stack);
	
	int i, count;
	char opt, bracket, check;
	
	for(i = 0; exp[i] != '\0'; i++) {
		// 공백이면 넘김 
		if(exp[i] == ' ') continue;
		
		check = exp[i];
		
		switch(check) {
			// 연산자 다음 값이 연산자인 경우 
			case '+': case '-': case '*': case '/':
				opt = exp[i + 1];
				if(opt == '+' || opt == '-' || opt == '*' || opt == '/') {
					printf(">> ' %c ' 연산자 오류!\n", opt);
					return -1;
				} else if(!isdigit(opt) && opt != '(' && opt != '{' && opt != '[' && opt != ' ') {
				// 연산자 다음 값이 괄호가 아니며, 숫자가 아니며, 공백이 아닌 경우 
					printf(">> ' %c ' 연산자 오류!\n", check);
					return -1;
				}
				break;
			
			// 여는 괄호인 경우 스택에 저장 
			case '(': case '{': case '[':
				S_Push(&stack, check);
				break;
			
			// 닫는 괄호인 경우 
			case ')': case '}': case ']':
				bracket = exp[i];
				
				// 스택이 존재 하지 않는 경우  
				if(S_Empty(&stack)) {
					printf(">> ' %c ' 문법 오류!\n", bracket);
					return -1;
				} else {
				// 스택이 존재 하지만 괄호가 다를 경우 
					if(bracket == ')') {
						if(S_Pop(&stack) != '(') {
							printf(">> ' %c ' 문법 오류!\n", bracket);
							return -1;
						}
					} else if(bracket == '}') {
						if(S_Pop(&stack) != '{') {
							printf(">> ' %c ' 문법 오류!\n", bracket);
							return -1;
						}
					} else {
						if(S_Pop(&stack) != '[') {
							printf(">> ' %c ' 문법 오류!\n", bracket);
							return -1;
						}
					}
				}
				break;
			
			default:
				// 숫자가 아닌 경우 , 문자인 경우 
				if(!isdigit(check)) {
					printf(">> 숫자를 입력해주세요 !\n");
					return -1;
				} else {
					bracket = exp[i + 1];
					
					// 숫자 다음이 연산자가 아닌 여는 괄호인 경우 
					if(bracket == '(' || bracket == '{' || bracket == '[' ) {
						printf(">> 괄호 문법 오류!\n");
						return -1;
					}
					
					count++;
				}
				break;
		}
	}
	
	// 하나도 입력되지 않았거나, 하나만 입력된 경우 
	if(!count || count == 1) {
		printf(">> 잘못된 형식입니다.\n");
		return -1;
	}
	
	// 비어 있지 않은 경우 작동 
	while(!S_Empty(&stack)) {
		// 여는 괄호가 많을 경우 
		opt = S_Pop(&stack);
		if(opt == '(' || opt == '{' || opt == '[') {
			printf(">> ' %c ' 문법 오류!\n", opt);
			return -1;
		}
	}
	
	return 0;
}
