#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

// 초기화 
void StackInit(Stack * pstack) {
	pstack->head = NULL;
}

// 비어있는지 확인 
int SIsEmpty(Stack * pstack) {
	if(pstack->head == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 삽입 
void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	pstack->head = newNode;
}

// 값 제거 및 반환 
Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("데이터를 찾을 수 없습니다!");
		exit(-1);
	}
	
	// 반환 데이터 , 노드 
	Data rdata = pstack->head->data;
	Node * rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	
	return rdata;
}

// 마지막 값 반환 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("데이터를 찾을 수 없습니다!");
		exit(-1);
	}
	
	return pstack->head->data;
}
