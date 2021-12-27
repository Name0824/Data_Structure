#include <stdio.h>
#include "ArrayList.h"

/*
typedef struct _ArrayList {
	LData arr[LIST_LEN];   // 리스트 저장소 
	int numOfData;        // 저장된 데이터의 수 
	int curPosition;     // 데이터 참조 위치 
} ArrayList;

typedef AraayList List;

// 초기화 기능 
// 데이터 삽입 기능 

// 첫 데이터 참조 기능 
// 두번째 데이터부터 끝 데이터까지 참조 기능 

// 데이터 삭제, First와 Next 함수와 같이 사용 
// 데이터의 수를 구하는 기능 
*/

void ListInit(List * plist)                       // 초기화 기능 
{
	plist->numOfData = 0;                   // 데이터의 개수는 처음 0 개 
	plist->curPosition = -1;               // 처음 인덱스가 0 부터 시작이므로 -1로 초기화 
}

void LInsert(List * plist, LData data)       // 데이터 삽입 기능 
{
	if(plist->numOfData >= LIST_LEN) {   // 리스트가 크면 안되니 조건을 지정 
		printf("저장이 불가능합니다.\n");
		return;
	}
	
	plist -> arr[plist -> numOfData++] = data;	
}

int LFirst(List * plist, LData * pdata)  // 첫 데이터 참조 기능 
{
	if(plist -> numOfData < 1) return FALSE;
	
	plist -> curPosition = 0;
	*pdata = plist -> arr[0];    // 리턴할때 TRUE, FALSE 반환을 했기때문에 반환값을 따로 만듬 
	
	return TRUE;
}

int LNext(List * plist, LData * pdata)  // 두번째 데이터부터 끝 데이터까지 참조 기능 
{
	if(plist->curPosition >= plist->numOfData - 1) return FALSE;
	
	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

LData LRemove(List * plist)           // 데이터 삭제, First와 Next 함수와 같이 사용 
{	
	LData rdata = plist->arr[plist->curPosition]; // 삭제된 값 반환하기 위해 작성한 코드
	
	plist -> numOfData--;
	
	int i;
	for(i = plist->curPosition; i < plist->numOfData; i++){
		plist -> arr[i] = plist -> arr[i + 1];
	}
	
	
	plist -> curPosition--;	// 위치 조정 
	
	return rdata;
}

int LCount(List * plist)             // 데이터의 수를 구하는 기능 
{
	return plist -> numOfData;
}
