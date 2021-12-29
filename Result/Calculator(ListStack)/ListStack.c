// 리스트 스택 소스 파일 

#include <stdio.h>		// 입출력 관련 
#include <stdlib.h>		// 동적할당 관련 

#include "ListStack.h"

void S_Init(Stack * pstack) {
	pstack->top = NULL;
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
}

Data S_Pop(Stack * pstack) {
	if(S_Empty(pstack)) {
		printf("\n>> 뽑아낼 데이터가 없습니다.");
		exit(-1);
	}
	
	Node * rnode = pstack->top;			// 삭제할 노드 저장 
	Data rdata	 = rnode->data;			// 반환할 데이터 저장 

	pstack->top	= pstack->top->next;	// 삭제하기전 최상단 위치를 다음으로 변경 
	free(rnode);						// 삭제 
	
	return rdata;						// 데이터 반환 
}

Data S_Peek(Stack * pstack) {
	if(S_Empty(pstack)) {
		printf("\n>> 확인할 데이터가 없습니다.");
		exit(-1);
	}
	
	return pstack->top->data;
}
