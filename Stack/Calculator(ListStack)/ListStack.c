// ����Ʈ ���� �ҽ� ���� 

#include <stdio.h>		// ����� ���� 
#include <stdlib.h>		// �����Ҵ� ���� 

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
		printf("\n>> �̾Ƴ� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	Node * rnode = pstack->top;			// ������ ��� ���� 
	Data rdata	 = rnode->data;			// ��ȯ�� ������ ���� 

	pstack->top	= pstack->top->next;	// �����ϱ��� �ֻ�� ��ġ�� �������� ���� 
	free(rnode);						// ���� 
	
	return rdata;						// ������ ��ȯ 
}

Data S_Peek(Stack * pstack) {
	if(S_Empty(pstack)) {
		printf("\n>> Ȯ���� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	return pstack->top->data;
}
