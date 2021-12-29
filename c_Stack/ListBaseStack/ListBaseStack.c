#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void S_Init(Stack * pstack) {
	pstack->top = NULL;
	pstack->num = 0;
}

int S_Empty(Stack * pstack) {
	if(pstack->top == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void S_Push(Stack * pstack, Data data) {
	Node * newStack = (Node*)malloc(sizeof(Node));
	newStack->data = data;
	
	newStack->next = pstack->top;
	pstack->top = newStack;
	
	pstack->num++;
}

Data S_Pop(Stack * pstack) {
	if(S_Empty(pstack)) {
		printf("저장된 데이터가 없습니다.");
		exit(-1);
	}
	
	Data rdata	 = pstack->top->data;	// 반환할 데이터 저장 
	Node * rnode = pstack->top;			// 삭제할 노드 저장 
	
	pstack->top = pstack->top->next;	// 삭제하기전 최상단 위치를 다음으로 변경 
	free(rnode);						// 삭제 
	
	pstack->num--;
	
	return rdata;						// 데이터 반환 
}

Data S_Peek(Stack * pstack) {
	if(S_Empty(pstack)) {
		printf("저장된 데이터가 없습니다.");
		exit(-1);
	}
	
	return pstack->top->data;
}

int S_Count(Stack * pstack) {
	return pstack->num;
}
