#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// 연결 리스트 초기화 
void ListInit(List * plist) {
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// 삽입 , 꼬리에 노드 추가 
void LInsert(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	// 처음 값이 없다면 
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
	// 두번째 값 
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	
	plist->numOfData++;
}

// 삽입, 머리에 노드 추가 
void LInsertFront(List * plist, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	// 처음 값이 없다면 
	if(plist->tail == NULL) {
		plist->tail = newNode;
		newNode->next = newNode;
	} else {
	// 두번째 값 
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}
	
	plist->numOfData++;
}

// 처음 
int LFirst(List * plist, Data * pdata) {
	// 만약 tail의 값이 없다면 
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
}

// 처음 이후, 2번째 이후 
int LNext(List * plist, Data * pdata) {
	// 만약 tail의 값이 없다면  
	if(plist->tail == NULL) {
		return FALSE;
	}
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	
	return TRUE;
}

// 삭제 
Data LRemove(List * plist) {
	// 삭제할 위치 
	Node * rpos = plist->cur;
	// 삭제할 데이터 반환용 
	Data rdata = rpos->data;
	
	// 예외 1 : 삭제할 데이터가 마지막 위치이면서 마지막 남은 데이터 라면? 
	// 예외 2 : 삭제할 데이터가 마지막 위치라면..
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
