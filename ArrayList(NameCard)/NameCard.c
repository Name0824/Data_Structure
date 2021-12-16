#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone) {
	NameCard * newCard = (NameCard*)malloc(sizeof(NameCard));
	
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);
	// strcpy 는 복사할곳, 복사할 값 
	
	return newCard;
}

void ShowNameCardInfo(NameCard * pcard) {
	printf("이름 : %s	전화번호 : %s \n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name) {
	return strcmp(pcard->name, name);
	// 문자열이 같다면, 0
	// 문자열이 다르면, 다른 수 
}

void ChangePhoneNum(NameCard * pcard, char * phone) {
	strcpy(pcard->phone, phone);
}
