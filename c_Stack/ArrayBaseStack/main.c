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
	
	// 배열에 저장된건 남아 있습니다, 단지 SPop에서는 못불러오는 것 
	for(i = 0; i < 10; i++) {
		printf("%d ", stack.stackArr[i]);
	}
	
	return 0;
}
