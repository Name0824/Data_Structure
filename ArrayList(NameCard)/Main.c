#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;		// ����Ʈ ����ü ���� ���� 
	ListInit(&list);	// ����Ʈ �� �ʱ�ȭ 
	LData nameCard;		// NameCard ����ü�� ���� ���� 

	while(1) {
		
		int conNum = 0;
		char name[NAME_LEN] = "";
		char phone[PHONE_LEN] = "";
		int ok = -1;
		
		/*
		NameCard newCard
		newCard.name , newCard.phone
		 
		����� ������ 
		 
		system("cls");    =  �ܼ�â ����� 
		system("pause");  =  �ܼ�â ���߱� 
		*/
	
		// �ܼ�â ��� 
		printf("************** MENU **************\n");
		printf("1. Insert      (������ �߰�) \n");
		printf("2. Search      (������ �˻�) \n");
		printf("3. Modify      (������ ����) \n");
		printf("4. Delete      (������ ����) \n");
		printf("5. Print All   (��� ������ ���) \n");
		printf("6. Count       (���� ������ �� ��ȯ) \n");
		printf("7. Exit        (���α׷� ����) \n");
		printf("\n");
		
		printf("Choose The Num : ");
		scanf("%d", &conNum);
		printf("\n");
		
		// ������ ���� 
		if(conNum == 1) { 
			printf("[   INSERT   ]\n");
			printf("�̸��� �Է����ּ��� : ");
			scanf("%s", &name);
			printf("��ȭ��ȣ�� �Է����ּ��� : ");
			scanf("%s", &phone);
			
			printf("\n");
			
			nameCard = MakeNameCard(name, phone);
			LInsert(&list, nameCard);
			
			system("cls"); 
		// Ư�� �ι� ã�� 
		} else if(conNum == 2) {
			printf("[   SEARCH   ]\n");
			printf("ã���� �̸��� �Է����ּ��� : ");
			scanf("%s", &name);
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, name)) {			
					printf("\n>> %s ���� ���� �Դϴ�.\n\n", nameCard->name);
					ShowNameCardInfo(nameCard);
					
					ok = 1;
				}
				
				while(LNext(&list, &nameCard)){
					if(!NameCompare(nameCard, name)) {						
						printf("\n>> %s ���� ���� �Դϴ�.\n\n", nameCard->name);
						ShowNameCardInfo(nameCard);
						
						ok = 1;
					}
				}		
			}
			
			if(ok == -1) {
				printf("\n>> ã���ô� ������ �����ϴ�.\n\n");
				system("pause");
				system("cls");
			} else {
				system("pause");
				system("cls");
			}
		// Ư�� �ι� ���� ���� 
		} else if(conNum == 3) {
			printf("[   MODIFY   ]\n");
			printf("ã���� �̸��� �Է����ּ��� : ");
			scanf("%s", &name);
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, name)) {
					printf("������ ��ȭ��ȣ�� �Է����ּ��� : ");
					scanf("%s", &phone);
					
					ChangePhoneNum(nameCard, phone);
					
					ok = 1;
					
					printf("\n>> %s ���� ������ ����Ǿ����ϴ�. \n\n", nameCard->name);
				}
				
				while(LNext(&list, &nameCard)){
					if(!NameCompare(nameCard, name)) {
						printf("������ ��ȭ��ȣ�� �Է����ּ��� : ");
						scanf("%s", &phone);
						
						ChangePhoneNum(nameCard, phone);
						
						ok = 1;
						
						printf("\n>> %s ���� ������ ����Ǿ����ϴ�. \n\n", nameCard->name);
					}
				}
			}
			
			if(ok == -1) {
				printf("\n>> ã���ô� ������ �����ϴ�.\n\n");
				system("pause");
				system("cls");
			} else {
				system("pause");
				system("cls");
			}
		// Ư�� �ι� ���� ����
		} else if(conNum == 4) { 
			printf("[   DELETE   ]\n");
			printf("������ �̸��� �Է����ּ��� : ");
			scanf("%s", &name);
			
			if(LFirst(&list, &nameCard)) {
				if(!NameCompare(nameCard, name)) {
					printf("\n>> %s ���� ������ �����Ǿ����ϴ�. \n\n", nameCard->name);
					nameCard = LRemove(&list);
					free(nameCard);
					
					ok = 1;
				}
				
				while(LNext(&list, &nameCard)){
					if(!NameCompare(nameCard, name)) {
						printf("\n>> %s ���� ������ �����Ǿ����ϴ�. \n\n", nameCard->name);
						nameCard = LRemove(&list);
						free(nameCard);
						
						ok = 1;
					}
				}
			}
			
			if(ok == -1) {
				printf("\n>> ã���ô� ������ �����ϴ�.\n\n");
				system("pause");
				system("cls");
			} else {
				system("pause");
				system("cls");
			}
			
		} else if(conNum == 5) { // ��� �ι� ��� 
			printf("[   PRINT ALL   ]\n");
			if(LFirst(&list, &nameCard)) {
				ShowNameCardInfo(nameCard);
				ok = 1;
		
				while(LNext(&list, &nameCard)){
					ShowNameCardInfo(nameCard);
					ok = 1;
				}
			printf("\n");
			}
			
			if(ok == -1) {
				printf("\n>> �����Ͱ� �������� �ʽ��ϴ�.\n\n");
				system("pause");
				system("cls");
			} else {
				system("pause");
				system("cls");
			}
		// ������ �� ��ȯ 
		} else if(conNum == 6) { 
			printf("[   COUNT   ]\n");
			printf("\n>> ���� %d ���� ������ ��ϵǾ��ֽ��ϴ�. \n\n", LCount(&list));
			
			system("pause"); 
			system("cls");
		// ���� 
		} else if(conNum == 7) {
			printf("���α׷��� �����մϴ�. \n");
			break;
		// �߸��� ��ȣ �Է� �� ��� 
		} else {
			printf(">> �߸��� ��ȣ�Դϴ�, �ٽ� �Է����ּ���. \n\n");
			
			// ǥ�� �Է� ���ۿ� ����� ��� ���ڸ� �����մϴ�. 
			rewind(stdin);
			
			system("pause"); // ���߱� 
			system("cls");
		}
	}
	
	return 0;
}
