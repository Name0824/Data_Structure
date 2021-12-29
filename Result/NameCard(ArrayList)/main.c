#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void) {
	List list;		// ����Ʈ ����ü ���� ���� 
	ListInit(&list);	// ����Ʈ �� �ʱ�ȭ 
	LData nameCard;		// NameCard ����ü�� ���� ���� 
	

	while(1) {
		int conNum = 0;
		int ok = -1;
		
		NameCard newCard;
		
		/*
		system("cls");    =  �ܼ�â ����� 
		system("pause");  =  �ܼ�â ���߱� 
		*/
		
		// �ܼ� �޴� ��� 
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

		switch(conNum) {
			// �ι� ���� ��� 
			case 1:
				printf("[   INSERT   ]\n");
				printf("�̸��� �Է����ּ��� : ");
				scanf("%s", &newCard.name);
				printf("��ȭ��ȣ�� �Է����ּ��� : ");
				scanf("%s", &newCard.phone);
				
				printf("\n");
				
				nameCard = MakeNameCard(newCard.name, newCard.phone);
				LInsert(&list, nameCard);
				
				break;
			// �ι� ���� ã��  
			case 2:
				printf("[   SEARCH   ]\n");
				printf("ã���� �̸��� �Է����ּ��� : ");
				scanf("%s", &newCard.name);
				
				if(LFirst(&list, &nameCard)) {
					if(!NameCompare(nameCard, newCard.name)) {			
						printf("\n>> %s ���� ���� �Դϴ�.\n", nameCard->name);
						ShowNameCardInfo(nameCard);
						
						ok = 1;
					}
					
					while(LNext(&list, &nameCard)){
						if(!NameCompare(nameCard, newCard.name)) {						
							printf("\n>> %s ���� ���� �Դϴ�.\n", nameCard->name);
							ShowNameCardInfo(nameCard);
							
							ok = 1;
						}
					}		
				}
				
				if(ok == -1) {
					printf("\n>> ã���ô� ������ �����ϴ�.\n");
				}
				
				printf("\n");
				
				break;
			// �ι� ���� ����  
			case 3:
				printf("[   MODIFY   ]\n");
				printf("ã���� �̸��� �Է����ּ��� : ");
				scanf("%s", &newCard.name);
				
				if(LFirst(&list, &nameCard)) {
					if(!NameCompare(nameCard, newCard.name)) {
						printf("������ ��ȭ��ȣ�� �Է����ּ��� : ");
						scanf("%s", &newCard.phone);
						
						ChangePhoneNum(nameCard, newCard.phone);
						
						ok = 1;
						
						printf("\n>> %s ���� ������ ����Ǿ����ϴ�. \n\n", nameCard->name);
					}
					
					while(LNext(&list, &nameCard)){
						if(!NameCompare(nameCard, newCard.name)) {
							printf("������ ��ȭ��ȣ�� �Է����ּ��� : ");
							scanf("%s", &newCard.phone);
							
							ChangePhoneNum(nameCard, newCard.phone);
							
							ok = 1;
							
							printf("\n>> %s ���� ������ ����Ǿ����ϴ�. \n\n", nameCard->name);
						}
					}
				}
				
				if(ok == -1) {
					printf("\n>> ã���ô� ������ �����ϴ�.\n\n");
				}
				
				break;
			// �ι� ���� ����  
			case 4:
				printf("[   DELETE   ]\n");
				printf("������ �̸��� �Է����ּ��� : ");
				scanf("%s", &newCard.name);
				
				if(LFirst(&list, &nameCard)) {
					if(!NameCompare(nameCard, newCard.name)) {
						printf("\n>> %s ���� ������ �����Ǿ����ϴ�. \n", nameCard->name);
						nameCard = LRemove(&list);
						free(nameCard);
						
						ok = 1;
					}
					
					while(LNext(&list, &nameCard)){
						if(!NameCompare(nameCard, newCard.name)) {
							printf("\n>> %s ���� ������ �����Ǿ����ϴ�. \n", nameCard->name);
							nameCard = LRemove(&list);
							free(nameCard);
							
							ok = 1;
						}
					}
				}
				
				if(ok == -1) {
					printf("\n>> ã���ô� ������ �����ϴ�.\n");
				}
				
				printf("\n");
				
				break;
			// �ι� ���� ��� ��� 
			case 5:
				printf("[   PRINT ALL   ]\n\n");
		
				if(LCount(&list) == 0) {
					printf(">> �����Ͱ� �������� �ʽ��ϴ�.\n");
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
			// ������ �� ��� 
			case 6:
				printf("[   COUNT   ]\n");
				printf("\n>> ���� %d ���� ������ ��ϵǾ��ֽ��ϴ�. \n\n", LCount(&list));
				
				break;
			// ���α׷� ���� 
			case 7:
				printf("���α׷��� �����մϴ�. \n");
				exit(-1);
			// �߸��� ��ȣ �� �߸� �Է� ���� ��� 
			default:
				printf(">> �߸��� ��ȣ�Դϴ�, �ٽ� �Է����ּ���. \n\n");
		}

		system("pause");
		system("cls");
		
		// ǥ�� �Է� ���ۿ� ����� ��� ���ڸ� �����մϴ�. 
		rewind(stdin);
	}
	
	return 0;
}
