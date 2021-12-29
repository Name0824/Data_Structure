#ifndef __LB_STACK_H__
#define __LB_STACK_H__

// ���� ��ũ�� ���� 
#define TRUE	1
#define FALSE	0

// ��ǥ �� 
typedef struct _point {
	int x;
	int y;
} Point;

// �ڷ��� ��Ī ���� 
typedef Point Data;

// ��� 
typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

// ����Ʈ 
typedef struct _listStack {
	Node * head;
} ListStack;

typedef ListStack Stack;

// �ʱ�ȭ, Empty Ȯ�� 
void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

// ����, ���� �� ��ȯ, �������� ��ȯ 
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif
