#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

// 논리값 정의 
#define TRUE	1
#define FALSE	0

// 데이터 별칭 정의 
typedef int Data;

// 노드 구조체  
typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

// 연결 리스트 
typedef struct _listQueue{
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

// 초기화, 빈값 확인, 삽입, 삭제 후 반환, 값 확인 
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
