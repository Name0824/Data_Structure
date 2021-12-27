#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

int main(void) {
	Stack stack;
	StackInit(&stack);
	
	int i;
	for(i = 1; i <= 10; i++) {
		SPush(&stack, i);
	}
	
	while(!SIsEmpty(&stack)) {
		printf("%d ", SPop(&stack));
	}
	
	printf("\n\n");
	
	// �迭�� ����Ȱ� ���� �ֽ��ϴ�, ���� SPop������ ���ҷ����� �� 
	for(i = 0; i < 10; i++) {
		printf("%d ", stack.stackArr[i]);
	}
	
	return 0;
}
