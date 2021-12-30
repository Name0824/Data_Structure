#include <stdio.h>		// 입출력 
#include <stdlib.h>		// 동적할당 

#include "ListBaseQueue.h"

// 초기화 
void QueueInit(Queue * pq) {
	pq->front = NULL;
	pq->rear  = NULL;
}

// 빈 값 확인 
int QIsEmpty(Queue * pq) {
	// if(pq->front == pq->rear) 될까? 
	if(pq->front == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 데이터 삽입 
void Enqueue(Queue * pq, Data data) {
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	} else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

// 데이터 삭제 후 반환 
Data Dequeue(Queue * pq) {
	if(QIsEmpty(pq)) {
		printf("저장된 데이터가 없습니다.");
		exit(-1);
	}
	
	Node * delNode = pq->front;
	Data delData = delNode->data;
	pq->front = pq->front->next;
	
	free(delNode);
	
	return delData;
}

// 데이터 값 확인 
Data QPeek(Queue * pq) {
	if(QIsEmpty(pq)) {
		printf("저장된 데이터가 없습니다.");
		exit(-1);
	}
	
	return pq->front->data; 
}
