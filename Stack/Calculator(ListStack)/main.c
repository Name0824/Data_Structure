#include <stdio.h>		// ����� ���� 
#include <string.h>		// ���ڿ� ���� 

#include "ListStack.h"
#include "Calculator.h"

int main(void) {
	
	char exp[101];
	Data result;

	while(1) {
		printf("���� ǥ����� �Է����ּ��� [���� : exit]");
		printf("\n\n");
		
		printf("�Է� : ");
		gets(exp);
		rewind(stdin);
		
		if(strcmp(exp, "exit") == 0) {
			break;
		}
		
		printf("\n");
		
		if(SyntaxSearch(exp) != -1) {
			printf("> ���� ǥ��� : %s\n", exp);
			
			ConvToPostfix(exp);
			printf("> ���� ǥ��� ��ȯ : %s\n", exp);
			
			printf("\n");
			result = CalcPostfix(exp);
			printf("> ��� �� : %.2lf\n", result);
		}
		printf("\n");
		system("pause");
		system("cls");
	}
}
