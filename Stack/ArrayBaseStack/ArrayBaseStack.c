#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

// �ʱ�ȭ 
void StackInit(Stack * pstack) {
	pstack->topIndex = -1;
}

// empty Ȯ�� 
int SIsEmpty(Stack * pstack) {
	if(pstack->topIndex == -1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// Full Ȯ�� 
int SIsFull(Stack * pstack) {
	// 0~99 �� 100�� �̹Ƿ� Stack_Len �κ��� 1 ���༭ 99�� �����. 
	if(pstack->topIndex >= STACK_LEN - 1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ������ �߰� 
void SPush(Stack * pstack, Data data) {
	if(SIsFull(pstack)) {
		printf("���̻� ������ �� �����ϴ�!");
		exit(-1);	// ���μ��� ����, return �̶� ����� 
	}
	
	pstack->topIndex++;
	pstack->stackArr[pstack->topIndex] = data;
}

// ������ ���� �� ��ȯ 
Data SPop(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("�����͸� ã�� �� �����ϴ�!");
		exit(-1);
	}
	
	int rIdx = pstack->topIndex;
	pstack->topIndex--;
	
	return pstack->stackArr[rIdx];
}

// �ֻ�� ������ Ȯ�� 
Data SPeek(Stack * pstack) {
	if(SIsEmpty(pstack)) {
		printf("�����͸� ã�� �� �����ϴ�!");
		exit(-1);
	}
	
	return pstack->stackArr[pstack->topIndex];
}
