#ifndef __AB_QUEUE_H__
#define __AB_QUEUE_H__

// 논리값 
#define TRUE	1
#define FALSE	0 

// 배열 갯수 
#define QUE_LEN	5

// 데이터 별칭 정의 
typedef int Data; 

// 큐 생성 
typedef struct _abQueue {
	int front;				// 앞 
	int rear;				// 뒤 
	Data queArr[QUE_LEN];	// 큐 배열 
	int count;
} ABQueue;

typedef ABQueue Queue;

// 초기화, 빈값 확인 
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

// 삽입, 삭제, 값 확인 
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

// 카운트 
int getCount(Queue * pq);

#endif
