#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	
	int input, comInput;
	int win = 0, draw = 0, lose = 0;
	char * arr[] = {"����", "����", "��"};
	
	while(1) {
		printf("����[1] , ����[2] , ��[3] �� �ϳ��� �Է����ּ���, ����[0]\n");
		printf("�Է� :: ");
		scanf("%d", &input);
		
		printf("\n");
		
		if(input == 0) {
			printf(">> ���������� ����\n");
			
			printf("\n===== [ ��� ] =====\n");
			printf("�� : %d  /  ���º� : %d  /  �й� : %d", win, draw, lose);
			exit(-1);
		}
		
		comInput = rand() % 3 + 1;
		
		if(input > 0 && input < 4) {
			
			printf("�� :: %s    vs   %s :: ��ǻ��\n", arr[input-1], arr[comInput-1]);
			
			if(input == 1 && comInput == 3 || input == 2 && comInput == 1 || input == 3 && comInput == 2) {
				printf(">> �¸�! \n");
				win++;
			} else if (input - comInput == 0) {
				printf(">> ���! \n");
				draw++;
			} else {
				printf(">> �й�! \n");
				lose++;
			}
		} else {
			printf("�߸��� �Է��Դϴ�. \n");
		}
		
		printf("\n");		
		system("pause");
		system("cls");
	}
	
	return 0;
}
