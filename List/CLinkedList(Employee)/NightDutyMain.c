#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// ���� ���� ��� 
#include "CLinkedList.h"
#include "Employee.h"
#include <time.h>

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
	strcpy(pemp->name, "Terry");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "Jhon");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "Holson");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "Sudny");
	LInsert(&list, pemp);
	
	pemp = WhosNightDuty(&list, "Terry", 3);
	ShowEmployeeInfo(pemp);

	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day) {
	Employee * ret;
	int size = LCount(plist);
	int i;
	
	LFirst(plist, &ret);
	if(strcmp(ret->name, name) == 0) {
		for(i = 0; i < day; i++) {
			LNext(plist, &ret);
		}
		return ret;
	}
	
	for(i = 1; i < size; i++) {
		LNext(plist, &ret);
		if(strcmp(ret->name, name) == 0) {
			for(i = 0; i < day; i++) {
				LNext(plist, &ret);
			}
			return ret;
		}
	}
	
	/*
	 
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
	 
	*/
}

void ShowEmployeeInfo(Employee * emp) {
	printf("Employee Name : %s\n", emp->name);
	printf("Employee Number : %d\n", emp->empNum);
}
