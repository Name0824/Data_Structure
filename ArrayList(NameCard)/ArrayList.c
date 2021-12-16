#include <stdio.h>
#include "ArrayList.h"

/*
typedef struct _ArrayList {
	LData arr[LIST_LEN];   // ����Ʈ ����� 
	int numOfData;        // ����� �������� �� 
	int curPosition;     // ������ ���� ��ġ 
} ArrayList;

typedef AraayList List;

// �ʱ�ȭ ��� 
// ������ ���� ��� 

// ù ������ ���� ��� 
// �ι�° �����ͺ��� �� �����ͱ��� ���� ��� 

// ������ ����, First�� Next �Լ��� ���� ��� 
// �������� ���� ���ϴ� ��� 
*/

void ListInit(List * plist)                       // �ʱ�ȭ ��� 
{
	plist->numOfData = 0;                   // �������� ������ ó�� 0 �� 
	plist->curPosition = -1;               // ó�� �ε����� 0 ���� �����̹Ƿ� -1�� �ʱ�ȭ 
}

void LInsert(List * plist, LData data)       // ������ ���� ��� 
{
	if(plist->numOfData >= LIST_LEN) {   // ����Ʈ�� ũ�� �ȵǴ� ������ ���� 
		printf("������ �Ұ����մϴ�.\n");
		return;
	}
	
	plist -> arr[plist -> numOfData++] = data;	
}

int LFirst(List * plist, LData * pdata)  // ù ������ ���� ��� 
{
	if(plist -> numOfData < 1) return FALSE;
	
	plist -> curPosition = 0;
	*pdata = plist -> arr[0];    // �����Ҷ� TRUE, FALSE ��ȯ�� �߱⶧���� ��ȯ���� ���� ���� 
	
	return TRUE;
}

int LNext(List * plist, LData * pdata)  // �ι�° �����ͺ��� �� �����ͱ��� ���� ��� 
{
	if(plist->curPosition >= plist->numOfData - 1) return FALSE;
	
	plist->curPosition++;
	*pdata = plist->arr[plist->curPosition];
	
	return TRUE;
}

LData LRemove(List * plist)           // ������ ����, First�� Next �Լ��� ���� ��� 
{	
	LData rdata = plist->arr[plist->curPosition]; // ������ �� ��ȯ�ϱ� ���� �ۼ��� �ڵ�
	
	plist -> numOfData--;
	
	int i;
	for(i = plist->curPosition; i < plist->numOfData; i++){
		plist -> arr[i] = plist -> arr[i + 1];
	}
	
	
	plist -> curPosition--;	// ��ġ ���� 
	
	return rdata;
}

int LCount(List * plist)             // �������� ���� ���ϴ� ��� 
{
	return plist -> numOfData;
}
