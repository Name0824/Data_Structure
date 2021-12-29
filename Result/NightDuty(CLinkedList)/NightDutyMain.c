#include <stdio.h>		// 입출력 관련 
#include <stdlib.h>		// 동적   관련 
#include <string.h>		// 문자열 관련 

#include "CLinkedList.h"
#include "Employee.h"

void ShowEmployeeInfo(Employee * emp);
Employee * WhosNightDuty(List * plist, char * name, int day);

int main(void) {
	Employee * pemp;
	
	// 원형 연결리스트 생성 및 초기화 
	List list;
	ListInit(&list);
	
	// 직원 목록 삽입 
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 1;
	strcpy(pemp->name, "강백호");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 2;
	strcpy(pemp->name, "귀철갑");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 3;
	strcpy(pemp->name, "호라이즌");
	LInsert(&list, pemp);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 4;
	strcpy(pemp->name, "세빌리");
	LInsert(&list, pemp);
	
	// 지정한 사람으로 부터 몇일 뒤 근무자는 누구인가 
	pemp = WhosNightDuty(&list, "강백호", 3);
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
	printf("사원 이름 : %s\n", emp->name);
	printf("사원 번호 : %d\n", emp->empNum);
}
