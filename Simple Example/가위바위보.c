#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	
	int input, comInput;
	int win = 0, draw = 0, lose = 0;
	char * arr[] = {"가위", "바위", "보"};
	
	while(1) {
		printf("가위[1] , 바위[2] , 보[3] 중 하나를 입력해주세요, 종료[0]\n");
		printf("입력 :: ");
		scanf("%d", &input);
		
		printf("\n");
		
		if(input == 0) {
			printf(">> 가위바위보 종료\n");
			
			printf("\n===== [ 결과 ] =====\n");
			printf("승 : %d  /  무승부 : %d  /  패배 : %d", win, draw, lose);
			exit(-1);
		}
		
		comInput = rand() % 3 + 1;
		
		if(input > 0 && input < 4) {
			
			printf("나 :: %s    vs   %s :: 컴퓨터\n", arr[input-1], arr[comInput-1]);
			
			if(input == 1 && comInput == 3 || input == 2 && comInput == 1 || input == 3 && comInput == 2) {
				printf(">> 승리! \n");
				win++;
			} else if (input - comInput == 0) {
				printf(">> 비김! \n");
				draw++;
			} else {
				printf(">> 패배! \n");
				lose++;
			}
		} else {
			printf("잘못된 입력입니다. \n");
		}
		
		printf("\n");		
		system("pause");
		system("cls");
	}
	
	return 0;
}
