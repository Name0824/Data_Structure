#ifndef __ARRAY_LIST_H__ // ArrayList.h ������ �������� �ʴ� ��쿡�� ������ �� �ֵ��� �ϴ� ��ũ�� 
// "If not defined"�� ���ڷμ� "~�� ����(define)���� �ʾҴٸ�" �̶�� ��
#define __ARRAY_LIST_H__

#define TRUE 1	// C������ TRUE��� ������ �����ϴ�. �׷��� ��ũ�η� define ���� ���Դϴ�. 
#define FALSE 0

#define LIST_LEN 100	// ����Ʈ�� ũ��� 100���� �����س��ҽ��ϴ�. 

// typedef int LData;           // �ڽ��� �� �ڷ��� ������ LData�� ���� 

#include "NameCard.h"
typedef NameCard * LData;

typedef struct _ArrayList {
	LData arr[LIST_LEN];   // ����Ʈ ����� 
	int numOfData;        // ����� �������� �� 
	int curPosition;     // ������ ���� ��ġ 
} ArrayList;

typedef ArrayList List;

void ListInit(List * plist);                // �ʱ�ȭ ��� 
void LInsert(List * plist, LData data);    // ������ ���� ��� 

int LFirst(List * plist, LData * pdata);  // ù ������ ���� ��� 
int LNext(List * plist, LData * pdata);  // �ι�° �����ͺ��� �� �����ͱ��� ���� ��� 

LData LRemove(List * plist);           // ������ ����, First�� Next �Լ��� ���� ��� 
int LCount(List * plist);             // �������� ���� ���ϴ� ��� 

#endif
