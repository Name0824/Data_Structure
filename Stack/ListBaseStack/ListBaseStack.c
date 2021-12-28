#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

// �ʱ�ȭ 
void StackInit(Stack * pstack) {
	pstack->head = NULL;
}

// ����ִ��� Ȯ�� 
int SIsEmpty(Stack * pstack) {
	if(pstack->head == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ���� 
void SPush(Stack * pstack, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->next = pstack->head;
	pstack->head = newNode;
}

// �� ���� �� ��ȯ 
Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("�����͸� ã�� �� �����ϴ�!");
		exit(-1);
	}
	
	// ��ȯ ������ , ��� 
	Data rdata = pstack->head->data;
	Node * rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	
	return rdata;
}

// ������ �� ��ȯ 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("�����͸� ã�� �� �����ϴ�!");
		exit(-1);
	}
	
	return pstack->head->data;
}
