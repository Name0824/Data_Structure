// ���� ǥ��� ��� �ҽ� ���� 

#include <stdio.h>		// ����� ���� 
#include <ctype.h>		// ��������, �������� 

#include "ListStack.h"
#include "Calculator.h"

Data CalcPostfix(char exp[]) {
	Stack stack;
	S_Init(&stack);
	
	Data opr1, opr2;
	int i, value, k = 0;
	
	for(i = 0; exp[i] != '\0'; i++) {
		if(isdigit(exp[i])) {
		// ���ڰ� �������� �ƴ��� Ȯ�� ( 0 ~ 9 ) 
			// ������ �ƴ϶�� k �� ��� 
			while(exp[i + k] != ' ') {
				k++;
			}
			
			// ���ڸ� ������ �ٲ��ִ� �Լ� atoi ��� 
			// ������ ���´ٸ� �ű������ ���� ��ȯ ( "100 20 300" => 100 ) 
			S_Push(&stack, atoi(&exp[i]));
			
			// i ���� ������ ��ġ�� ��ҷ� ���� 
			i += k;
			// k �� ���� �ٽ� 0���� ������ش�. 
			k = 0;
		} else {
			// �����̶�� �ѱ��. 
			if(exp[i] == ' ') continue;
			
			// ���ÿ� �ִ� ���ڸ� ���� �� ������ �־���, ���� ������ ���� 
			opr2 = S_Pop(&stack);
			opr1 = S_Pop(&stack);
			
			// �����ڿ� ���� ��� 
			switch(exp[i]) {
				case '+': S_Push(&stack, opr1 + opr2); break;
				case '-': S_Push(&stack, opr1 - opr2); break;
				case '*': S_Push(&stack, opr1 * opr2); break;
				case '/': S_Push(&stack, opr1 / opr2); break;
			}
		}
	}
	
	// ���������� ���ÿ� �ִ� ���� ���� 
	return S_Pop(&stack);
}
