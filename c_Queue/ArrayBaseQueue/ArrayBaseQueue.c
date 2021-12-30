#include <stdio.h>		// 입출력 
#include <stdlib.h>		// 동적 할당 

#include "ArrayBaseQueue.h"

// 큐 초기화 
void QueueInit(Queue * pq) {
	pq->front = 0;
	pq->rear  = 0;
	pq->count = 0;
}

// 큐가 같은 위치에 있으면 비어 있는 값 
int QIsEmpty(Queue * pq) {
	if(pq->front == pq->rear) {
		return TRUE;
	} else {
		return FALSE;
	}
}

// 만약 매개변수 값이 지정한 길이 - 1 이랑 같을 경우 0으로, 아니라면 매개변수 + 1 
int NextPosIdx(int pos) {
	if(pos == QUE_LEN - 1) {
		return 0;
	} else {
		return pos + 1;
	}
}

void Enqueue(Queue * pq, Data data) {
	// 큐가 꽉 찬 경우 예외처리 [exit(-1)]
	if(NextPosIdx(pq->rear) == pq->front) {
		printf("큐에 저장할 공간이 부족합니다.\n");
		exit(-1);
	}
	
	// 반복이 될 수 있는 원인, 0으로 만들어주기때문 
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
	
	pq->count++;
	
	printf("[%d] ", pq->rear);
}

Data Dequeue(Queue * pq) {
	// 큐가 빈 경우 예외처리 [exit(-1)]
	if(QIsEmpty(pq)) {
		printf("큐에 데이터가 존재하지 않습니다.\n");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);
	
	pq->count--;
	
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq) {
	// 큐가 빈 경우 예외처리 [exit(-1)]
	if(QIsEmpty(pq)) {
		printf("큐에 데이터가 존재하지 않습니다.\n");
		exit(-1);
	}
	
	return pq->queArr[NextPosIdx(pq->front)];
}

int getCount(Queue * pq) {
	return pq->count;
}
