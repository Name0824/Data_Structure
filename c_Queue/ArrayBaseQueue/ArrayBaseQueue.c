#include <stdio.h>		// ����� 
#include <stdlib.h>		// ���� �Ҵ� 

#include "ArrayBaseQueue.h"

// ť �ʱ�ȭ 
void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear  = 0;
	pq->count = 0;
}

// ť�� ���� ��ġ�� ������ ��� �ִ� �� 
int QIsEmpty(Queue * pq) {
	if(pq->front == pq->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// ���� �Ű����� ���� ������ ���� - 1 �̶� ���� ��� 0����, �ƴ϶�� �Ű����� + 1 
int NextPosIdx(int pos) {
	if(pos == QUE_LEN - 1) {
		return 0;
	} else {
		return pos + 1;
	}
}

void Enqueue(Queue * pq, Data data) {
	// ť�� �� �� ��� ����ó�� [exit(-1)]
	if(NextPosIdx(pq->rear) == pq->front) {
		printf("ť�� ������ ������ �����մϴ�.\n");
		exit(-1);
	}
	
	// �ݺ��� �� �� �ִ� ����, 0���� ������ֱ⶧�� 
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
	
	pq->count++;
	
	printf("[%d] ", pq->rear);
}

Data Dequeue(Queue * pq) {
	// ť�� �� ��� ����ó�� [exit(-1)]
	if(QIsEmpty(pq)) {
		printf("ť�� �����Ͱ� �������� �ʽ��ϴ�.\n");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);
	
	pq->count--;
	
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq) {
	// ť�� �� ��� ����ó�� [exit(-1)]
	if(QIsEmpty(pq)) {
		printf("ť�� �����Ͱ� �������� �ʽ��ϴ�.\n");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)];
}

int getCount(Queue * pq) {
	return pq->count;
}
