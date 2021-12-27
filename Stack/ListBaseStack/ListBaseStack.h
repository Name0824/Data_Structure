#ifndef __LB_STACK_H__
#define __LB_STACK_H__

// 논리값 매크로 정의 
#define TRUE	1
#define FALSE	0

// 자료형 별칭 정의 
typedef int Data;

typedef struct _node {
	Data data;
	struct _node * next;
} Node; 

typedef struct _listStack {
	Node * head;
} ListStack;

typedef ListStack Stack;

// 초기화, Empty 확인 
void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

// 삽입, 제거 후 반환, 마지막값 반환 
int SPush(Stack * pstack, Data data);
int SPop(Stack * pstack);
int SPeek(Stack * pstack);

#endif
