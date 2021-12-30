#ifndef __LB_QUEUE_H__
#define __LB_QUEUE_H__

// ���� ���� 
#define TRUE	1
#define FALSE	0

// ������ ��Ī ���� 
typedef int Data;

// ��� ����ü  
typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

// ���� ����Ʈ 
typedef struct _listQueue{
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

// �ʱ�ȭ, �� Ȯ��, ����, ���� �� ��ȯ, �� Ȯ�� 
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
