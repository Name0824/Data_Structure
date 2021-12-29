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
		printf("����� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	Data rdata	 = pstack->top->data;	// ��ȯ�� ������ ���� 
	Node * rnode = pstack->top;			// ������ ��� ���� 
	
	pstack->top = pstack->top->next;	// �����ϱ��� �ֻ�� ��ġ�� �������� ���� 
	free(rnode);						// ���� 
	
	pstack->num--;
	
	return rdata;						// ������ ��ȯ 
}

Data S_Peek(Stack * pstack) {
	if(S_Empty(pstack)) {
		printf("����� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	return pstack->top->data;
}

int S_Count(Stack * pstack) {
	return pstack->num;
}
