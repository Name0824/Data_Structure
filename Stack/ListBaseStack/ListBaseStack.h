#ifndef __LB_STACK_H__
#define __LB_STACK_H__

// 논리값 매크로 정의 
#define TRUE	1
#define FALSE	0

// 자료형 별칭 정의 
typedef int Data;

// 노드 
typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

// 리스트 스택 
typedef struct _listStack {
	Node * head;
} ListStack;

typedef ListStack Stack;

// 초기화, Empty 확인, 삽입, 제거 후 반환, 마지막값 반환
void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif
