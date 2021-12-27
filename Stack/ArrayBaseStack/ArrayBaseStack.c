#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

/*
typedef struct _arraystack {
	Data stackArr[STACK_LEN];	// 데이터 넣을 배열 공간 
	int topIndex;				// 최상단 인덱스 
} ArrayStack;
*/

// 초기화, empty 확인, Full 확인 
void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex == -1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

int SIsFull(Stack * pstack) {
	// 0~99 는 100개 이므로 Stack_Len 부분을 1 빼줘서 99로 맞춘다. 
	if(pstack->topIndex >= STACK_LEN - 1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 데이터 추가, 삭제 
void SPush(Stack * pstack, Data data) {
	if(SIsFull(pstack)) {
		printf("Stack OverFlow!");
		exit(-1);	// 프로세스 종료, return 이랑 비슷함 
	}
	
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Data Is Not Found!");
		exit(-1);
	}
	
	int rIdx = pstack->topIndex;
	pstack->topIndex--;
	
	return pstack->stackArr[rIdx];
}

// 스택 최상단 데이터 확인 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Data Is Not Found!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
