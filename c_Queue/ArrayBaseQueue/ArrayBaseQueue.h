#ifndef __AB_QUEUE_H__
#define __AB_QUEUE_H__

// ���� 
#define TRUE	1
#define FALSE	0 

// �迭 ���� 
#define QUE_LEN	5

// ������ ��Ī ���� 
typedef int Data; 

// ť ���� 
typedef struct _abQueue {
	int front;				// �� 
	int rear;				// �� 
	Data queArr[QUE_LEN];	// ť �迭 
	int count;
} ABQueue;

typedef ABQueue Queue;

// �ʱ�ȭ, �� Ȯ�� 
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

// ����, ����, �� Ȯ�� 
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

// ī��Ʈ 
int getCount(Queue * pq);

#endif
