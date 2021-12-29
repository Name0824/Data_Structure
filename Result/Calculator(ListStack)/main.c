#include <stdio.h>		// 입출력 관련 
#include <string.h>		// 문자열 관련 

#include "ListStack.h"
#include "Calculator.h"

int main(void) {
	
	char exp[101];
	Data result;

	while(1) {
		printf("중위 표기법을 입력해주세요 [종료 : exit]");
		printf("\n\n");
		
		printf("입력 : ");
		gets(exp);
		rewind(stdin);
		
		if(strcmp(exp, "exit") == 0) {
			break;
		}
		
		printf("\n");
		
		if(SyntaxSearch(exp) != -1) {
			printf("> 중위 표기법 : %s\n", exp);
			
			ConvToPostfix(exp);
			printf("> 후위 표기법 변환 : %s\n", exp);
			
			printf("\n");
			result = CalcPostfix(exp);
			printf("> 계산 값 : %.2lf\n", result);
		}
		printf("\n");
		system("pause");
		system("cls");
	}
}
