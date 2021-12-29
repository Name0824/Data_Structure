#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;		// 리스트 구조체 변수 생성 
	ListInit(&list);	// 리스트 값 초기화 
	LData nameCard;		// NameCard 구조체의 변수 생성 
	

	while(1) {
		int conNum = 0;
		int ok = -1;
		
		NameCard newCard;
		
		/*
		system("cls");    =  콘솔창 지우기 
		system("pause");  =  콘솔창 멈추기 
		*/
		
		// 콘솔 메뉴 출력 
		printf("************** MENU **************\n");
		printf("1. Insert      (데이터 추가) \n");
		printf("2. Search      (데이터 검색) \n");
		printf("3. Modify      (데이터 수정) \n");
		printf("4. Delete      (데이터 삭제) \n");
		printf("5. Print All   (모든 데이터 출력) \n");
		printf("6. Count       (현재 데이터 수 반환) \n");
		printf("7. Exit        (프로그램 종료) \n");
		printf("\n");
		
		printf("Choose The Num : ");
		scanf("%d", &conNum);
		printf("\n");

		switch(conNum) {
			// 인물 정보 등록 
			case 1:
				printf("[   INSERT   ]\n");
				printf("이름을 입력해주세요 : ");
				scanf("%s", &newCard.name);
				printf("전화번호를 입력해주세요 : ");
				scanf("%s", &newCard.phone);
				
				printf("\n");
				
				nameCard = MakeNameCard(newCard.name, newCard.phone);
				LInsert(&list, nameCard);
				
				break;
			// 인물 정보 찾기  
			case 2:
				printf("[   SEARCH   ]\n");
				printf("찾으실 이름을 입력해주세요 : ");
				scanf("%s", &newCard.name);
				
				if(LFirst(&list, &nameCard)) {
					if(!NameCompare(nameCard, newCard.name)) {			
						printf("\n>> %s 님의 정보 입니다.\n", nameCard->name);
						ShowNameCardInfo(nameCard);
						
						ok = 1;
					}
					
					while(LNext(&list, &nameCard)){
						if(!NameCompare(nameCard, newCard.name)) {						
							printf("\n>> %s 님의 정보 입니다.\n", nameCard->name);
							ShowNameCardInfo(nameCard);
							
							ok = 1;
						}
					}		
				}
				
				if(ok == -1) {
					printf("\n>> 찾으시는 정보가 없습니다.\n");
				}
				
				printf("\n");
				
				break;
			// 인물 정보 수정  
			case 3:
				printf("[   MODIFY   ]\n");
				printf("찾으실 이름을 입력해주세요 : ");
				scanf("%s", &newCard.name);
				
				if(LFirst(&list, &nameCard)) {
					if(!NameCompare(nameCard, newCard.name)) {
						printf("변경할 전화번호를 입력해주세요 : ");
						scanf("%s", &newCard.phone);
						
						ChangePhoneNum(nameCard, newCard.phone);
						
						ok = 1;
						
						printf("\n>> %s 님의 정보가 변경되었습니다. \n\n", nameCard->name);
					}
					
					while(LNext(&list, &nameCard)){
						if(!NameCompare(nameCard, newCard.name)) {
							printf("변경할 전화번호를 입력해주세요 : ");
							scanf("%s", &newCard.phone);
							
							ChangePhoneNum(nameCard, newCard.phone);
							
							ok = 1;
							
							printf("\n>> %s 님의 정보가 변경되었습니다. \n\n", nameCard->name);
						}
					}
				}
				
				if(ok == -1) {
					printf("\n>> 찾으시는 정보가 없습니다.\n\n");
				}
				
				break;
			// 인물 정보 삭제  
			case 4:
				printf("[   DELETE   ]\n");
				printf("삭제할 이름을 입력해주세요 : ");
				scanf("%s", &newCard.name);
				
				if(LFirst(&list, &nameCard)) {
					if(!NameCompare(nameCard, newCard.name)) {
						printf("\n>> %s 님의 정보가 삭제되었습니다. \n", nameCard->name);
						nameCard = LRemove(&list);
						free(nameCard);
						
						ok = 1;
					}
					
					while(LNext(&list, &nameCard)){
						if(!NameCompare(nameCard, newCard.name)) {
							printf("\n>> %s 님의 정보가 삭제되었습니다. \n", nameCard->name);
							nameCard = LRemove(&list);
							free(nameCard);
							
							ok = 1;
						}
					}
				}
				
				if(ok == -1) {
					printf("\n>> 찾으시는 정보가 없습니다.\n");
				}
				
				printf("\n");
				
				break;
			// 인물 정보 모두 출력 
			case 5:
				printf("[   PRINT ALL   ]\n\n");
		
				if(LCount(&list) == 0) {
					printf(">> 데이터가 존재하지 않습니다.\n");
				} else {
					if(LFirst(&list, &nameCard)) {
						ShowNameCardInfo(nameCard);
			
						while(LNext(&list, &nameCard)) {
							ShowNameCardInfo(nameCard);
						}
					}
				} 

				printf("\n");
				
				break;
			// 데이터 수 출력 
			case 6:
				printf("[   COUNT   ]\n");
				printf("\n>> 현재 %d 개의 정보가 등록되어있습니다. \n\n", LCount(&list));
				
				break;
			// 프로그램 종료 
			case 7:
				printf("프로그램을 종료합니다. \n");
				exit(-1);
			// 잘못된 번호 및 잘못 입력 했을 경우 
			default:
				printf(">> 잘못된 번호입니다, 다시 입력해주세요. \n\n");
		}

		system("pause");
		system("cls");
		
		// 표준 입력 버퍼에 저장된 모든 문자를 제거합니다. 
		rewind(stdin);
	}
	
	return 0;
}
