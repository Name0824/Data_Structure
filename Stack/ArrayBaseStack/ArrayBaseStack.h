#ifndef __AB_STACK_H__
#define __AB_STACK_H__

// 논리값 매크로 정의 
#define	TRUE	1
#define	FALSE	0

// 배열리스트라 배열 크기 지정 
#define STACK_LEN	100

// Data 별칭 지정 
typedef int Data;

// 리스트 구조체 생성 
typedef struct _arraystack {
	Data stackArr[STACK_LEN];	// 데이터 넣을 배열 공간 
	int topIndex;				// 최상단 인덱스 
} ArrayStack;

typedef ArrayStack Stack;

// 초기화, empty 확인, Full 확인 
void StackInit(Stack * pstack); 
int SIsEmpty(Stack * pstack);
int SIsFull(Stack * pstack);

// 데이터 추가, 삭제 
void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);

// 스택 최상단 데이터 확인 
Data SPeek(Stack * pstack);

#endif
