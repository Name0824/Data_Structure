#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

// �ʱ�ȭ, Empty Ȯ�� 
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

// ����, ���� �� ��ȯ, �������� ��ȯ 
void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	pstack->head = newNode;
	
	printf("[���� �߰�] :: [%d, %d] > \n", data.x, data.y);
}

Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("�̾Ƴ� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	// ��ȯ ������ , ��� 
	Data rdata = pstack->head->data;
	Node * rnode = pstack->head;

	pstack->head = pstack->head->next;
	
	printf("[���� ����] :: [%d, %d] > \n", rdata.x, rdata.y);
	
	free(rnode);
	
	return rdata;
}

Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("Ȯ���� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	return pstack->head->data;
}
