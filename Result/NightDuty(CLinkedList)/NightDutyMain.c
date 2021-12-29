#include <stdio.h>		// ����� ���� 
#include <stdlib.h>		// ����   ���� 
#include <string.h>		// ���ڿ� ���� 

#include "CLinkedList.h"
#include "Employee.h"

void ShowEmployeeInfo(Employee * emp);
Employee * WhosNightDuty(List * plist, char * name, int day);

int main(void) {
	Employee * pemp;
	
	// ���� ���Ḯ��Ʈ ���� �� �ʱ�ȭ 
	List list;
	ListInit(&list);
	
	// ���� ��� ���� 
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "����ȣ");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "��ö��");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "ȣ������");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "������");
	LInsert(&list, pemp);
	
	// ������ ������� ���� ���� �� �ٹ��ڴ� �����ΰ� 
	pemp = WhosNightDuty(&list, "����ȣ", 3);
	ShowEmployeeInfo(pemp);

	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day) {
	Employee * ret;
	int size = LCount(plist);
	int i;
	
	LFirst(plist, &ret);
	if(strcmp(ret->name, name) != 0) {
		for(i = 1; i < size; i++) {
			LNext(plist, &ret);
			
			if(strcmp(ret->name, name) == 0) {
				break;
			}
		}
	}
	
	for(i = 0; i < day; i++) {
		LNext(plist, &ret);
	}
	 
	return ret;
}

void ShowEmployeeInfo(Employee * emp) {
	printf("��� �̸� : %s\n", emp->name);
	printf("��� ��ȣ : %d\n", emp->empNum);
}
