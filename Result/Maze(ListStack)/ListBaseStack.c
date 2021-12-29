#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

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
void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	pstack->head = newNode;
	
	printf("[스택 추가] :: [%d, %d] > \n", data.x, data.y);
}

Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("뽑아낼 데이터가 없습니다.");
		exit(-1);
	}
	
	// 반환 데이터 , 노드 
	Data rdata = pstack->head->data;
	Node * rnode = pstack->head;

	pstack->head = pstack->head->next;
	
	printf("[스택 삭제] :: [%d, %d] > \n", rdata.x, rdata.y);
	
	free(rnode);
	
	return rdata;
}

Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("확인할 데이터가 없습니다.");
		exit(-1);
	}
	
	return pstack->head->data;
}
