#ifndef __AB_STACK_H__
#define __AB_STACK_H__

// ���� ��ũ�� ���� 
#define	TRUE	1
#define	FALSE	0

// �迭����Ʈ�� �迭 ũ�� ���� 
#define STACK_LEN	100

// Data ��Ī ���� 
typedef int Data;

// ����Ʈ ����ü ���� 
typedef struct _arraystack {
	Data stackArr[STACK_LEN];	// ������ ���� �迭 ���� 
	int topIndex;				// �ֻ�� �ε��� 
} ArrayStack;

typedef ArrayStack Stack;

// �ʱ�ȭ, empty Ȯ��, Full Ȯ�� 
void StackInit(Stack * pstack); 
int SIsEmpty(Stack * pstack);
int SIsFull(Stack * pstack);

// ������ �߰�, ���� 
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);

// ���� �ֻ�� ������ Ȯ�� 
Data SPeek(Stack * pstack);

#endif
