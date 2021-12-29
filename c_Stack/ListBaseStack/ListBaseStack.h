#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

// ���� ���� 
#define TRUE	1
#define FALSE	0

// DATA ��Ī 
typedef int Data;

// ��� 
typedef struct _node {
	Data data;
	struct _node * next;
} Node;

// ����Ʈ 
typedef struct _stackList {
	Node * top;
	int num;
} StackList;

typedef StackList Stack;

void S_Init(Stack * pstack);				// �ʱ�ȭ 
int S_Empty(Stack * pstack);				// ����ִ��� Ȯ�� 
void S_Push(Stack * pstack, Data data);		// ������ ���� 
Data S_Pop(Stack * pstack);					// ������ ���� �� ������ ��ȯ 
Data S_Peek(Stack * pstack);				// ������ ������ ��ȯ 
int S_Count(Stack * pstack);				// ���� ��� 

#endif

