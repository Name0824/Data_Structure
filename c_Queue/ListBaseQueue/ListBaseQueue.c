#include <stdio.h>		// ����� 
#include <stdlib.h>		// �����Ҵ� 

#include "ListBaseQueue.h"

// �ʱ�ȭ 
void QueueInit(Queue * pq) {
	pq->front = NULL;
	pq->rear  = NULL;
}

// �� �� Ȯ�� 
int QIsEmpty(Queue * pq) {
	// if(pq->front == pq->rear) �ɱ�? 
	if(pq->front == NULL) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ������ ���� 
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

// ������ ���� �� ��ȯ 
Data Dequeue(Queue * pq) {
	if(QIsEmpty(pq)) {
		printf("����� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	Node * delNode = pq->front;
	Data delData = delNode->data;
	pq->front = pq->front->next;
	
	free(delNode);
	
	return delData;
}

// ������ �� Ȯ�� 
Data QPeek(Queue * pq) {
	if(QIsEmpty(pq)) {
		printf("����� �����Ͱ� �����ϴ�.");
		exit(-1);
	}
	
	return pq->front->data; 
}
