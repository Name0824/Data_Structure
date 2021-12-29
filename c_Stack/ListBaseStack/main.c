#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

int main(void) {
	Stack stack;
	S_Init(&stack);
	Data data;
	
	printf("���ڸ� �Է����ּ���.\n");
	printf(">> 0�� �Է��ϸ� �Է��� ����˴ϴ�.\n");
	
	while(1) {
		scanf("%d", &data);
		
		if(data == 0) {
			break;
		}
		
		S_Push(&stack, data);
	}
	
	printf("\n>> ���\n");
	int text;
	while(S_Count(&stack) != 1) {
		text = S_Pop(&stack);
		printf("%d, ", text);
	}
	
	text = S_Pop(&stack);
	printf("%d", text);
	
	return 0;
}
