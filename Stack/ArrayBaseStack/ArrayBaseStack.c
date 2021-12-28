#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

// 초기화 
void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

// empty 확인 
int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex == -1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// Full 확인 
int SIsFull(Stack * pstack) {
	// 0~99 는 100개 이므로 Stack_Len 부분을 1 빼줘서 99로 맞춘다. 
	if(pstack->topIndex >= STACK_LEN - 1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 데이터 추가 
void SPush(Stack * pstack, Data data) {
	if(SIsFull(pstack)) {
		printf("더이상 저장할 수 없습니다!");
		exit(-1);	// 프로세스 종료, return 이랑 비슷함 
	}
	
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

// 데이터 삭제 후 반환 
Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("데이터를 찾을 수 없습니다!");
		exit(-1);
	}
	
	int rIdx = pstack->topIndex;
	pstack->topIndex--;
	
	return pstack->stackArr[rIdx];
}

// 최상단 데이터 확인 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("데이터를 찾을 수 없습니다!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
