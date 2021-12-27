#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone) {
	NameCard * newCard = (NameCard*)malloc(sizeof(NameCard));
	
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);
	// strcpy �� �����Ұ�, ������ �� 
	
	return newCard;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("�̸� : %s	��ȭ��ȣ : %s \n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name) {
	return strcmp(pcard->name, name);
	// ���ڿ��� ���ٸ�, 0
	// ���ڿ��� �ٸ���, �ٸ� �� 
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strcpy(pcard->phone, phone);
}
