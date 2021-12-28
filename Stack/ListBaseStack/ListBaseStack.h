#ifndef __LB_STACK_H__
#define __LB_STACK_H__

// ���� ��ũ�� ���� 
#define TRUE	1
#define FALSE	0

// �ڷ��� ��Ī ���� 
typedef int Data;

// ��� 
typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

// ����Ʈ ���� 
typedef struct _listStack {
	Node * head;
} ListStack;

typedef ListStack Stack;

// �ʱ�ȭ, Empty Ȯ��, ����, ���� �� ��ȯ, �������� ��ȯ
void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif
