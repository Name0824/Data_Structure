#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"
/*
typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

typedef struct _listStack {
	Node * head;
} ListStack;
*/

// 초기화, Empty 확인 
void StackInit(Stack * pstack) {
	pstack->head = NULL;
}

int SIsEmpty(Stack * pstack) {
	if(pstack->head == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 삽입, 제거 후 반환, 마지막값 반환 
int SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	pstack->head = newNode;
	
}

int SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	// 반환 데이터 , 노드 
	Data rdata = pstack->head->data;
	Node * rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	
	return rdata;
}

int SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	return pstack->head->data;
}
