#ifndef __LIST_BASE_STACK_H__
#define __LIST_BASE_STACK_H__

// 논리값 정의 
#define TRUE	1
#define FALSE	0

// DATA 별칭 
typedef int Data;

// 노드 
typedef struct _node {
	Data data;
	struct _node * next;
} Node;

// 리스트 
typedef struct _stackList {
	Node * top;
	int num;
} StackList;

typedef StackList Stack;

void S_Init(Stack * pstack);				// 초기화 
int S_Empty(Stack * pstack);				// 비어있는지 확인 
void S_Push(Stack * pstack, Data data);		// 데이터 삽입 
Data S_Pop(Stack * pstack);					// 데이터 삭제 후 데이터 반환 
Data S_Peek(Stack * pstack);				// 마지막 데이터 반환 
int S_Count(Stack * pstack);				// 갯수 출력 

#endif

