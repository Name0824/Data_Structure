#ifndef __ARRAY_LIST_H__ // ArrayList.h 파일이 존재하지 않는 경우에만 참조될 수 있도록 하는 매크로 
// "If not defined"의 약자로서 "~을 정의(define)하지 않았다면" 이라는 뜻
#define __ARRAY_LIST_H__

#define TRUE 1	// C언어에서는 TRUE라는 논리값이 없습니다. 그래서 매크로로 define 해준 것입니다. 
#define FALSE 0

#define LIST_LEN 100	// 리스트의 크기는 100으로 지정해놓았습니다. 

// typedef int LData;           // 자신이 쓸 자료형 변수를 LData로 정의 

#include "NameCard.h"
typedef NameCard * LData;

typedef struct _ArrayList {
	LData arr[LIST_LEN];   // 리스트 저장소 
	int numOfData;        // 저장된 데이터의 수 
	int curPosition;     // 데이터 참조 위치 
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist);                // 초기화 기능 
void LInsert(List * plist, LData data);    // 데이터 삽입 기능 

int LFirst(List * plist, LData * pdata);  // 첫 데이터 참조 기능 
int LNext(List * plist, LData * pdata);  // 두번째 데이터부터 끝 데이터까지 참조 기능 

LData LRemove(List * plist);           // 데이터 삭제, First와 Next 함수와 같이 사용 
int LCount(List * plist);             // 데이터의 수를 구하는 기능 

#endif
