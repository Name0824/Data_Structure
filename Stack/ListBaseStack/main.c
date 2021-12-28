#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

int main(void) {
	Stack stack;
	S_Init(&stack);
	Data data;
	
	printf("숫자를 입력해주세요.\n");
	printf(">> 0을 입력하면 입력이 종료됩니다.\n");
	
	while(1) {
		scanf("%d", &data);
		
		if(data == 0) {
			break;
		}
		
		S_Push(&stack, data);
	}
	
	printf("\n>> 출력\n");
	int text;
	while(S_Count(&stack) != 1) {
		text = S_Pop(&stack);
		printf("%d, ", text);
	}
	
	text = S_Pop(&stack);
	printf("%d", text);
	
	return 0;
}
