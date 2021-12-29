#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// ���� ����Ʈ �ʱ�ȭ 
void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// ���� , ������ ��� �߰� 
void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	// ó�� ���� ���ٸ� 
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
	// �ι�° �� 
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	
	plist->numOfData++;
}

// ����, �Ӹ��� ��� �߰� 
void LInsertFront(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	// ó�� ���� ���ٸ� 
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
	// �ι�° �� 
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	
	plist->numOfData++;
}

// ó�� 
int LFirst(List * plist, Data * pdata) {
	// ���� tail�� ���� ���ٸ� 
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
}

// ó�� ����, 2��° ���� 
int LNext(List * plist, Data * pdata) {
	// ���� tail�� ���� ���ٸ�  
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
}

// ���� 
Data LRemove(List * plist) {
	// ������ ��ġ 
	Node * rpos = plist->cur;
	// ������ ������ ��ȯ�� 
	Data rdata = rpos->data;
	
	// ���� 1 : ������ �����Ͱ� ������ ��ġ�̸鼭 ������ ���� ������ ���? 
	// ���� 2 : ������ �����Ͱ� ������ ��ġ���..
	if(rpos == plist->tail) {
		if(plist->tail == plist->tail->next) {
			plist->tail = NULL;
		} else {
			plist->tail = plist->before;
		}
	}
	
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	
	plist->numOfData--;
	
	return rdata;
}

int LCount(List * plist) {
	return plist->numOfData;
}
