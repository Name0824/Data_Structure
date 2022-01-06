#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));	// ���� �õ� �� 
	
	int input[3], comInput[3];
	
	int strike, ball, count = 0;
	int i, j;
	
	// ��ǻ�� �Է� 
	for(i = 0; i < 3; i++) {
		comInput[i] = rand() % 10;
		
		// �ߺ� ���̸� �� ������ 
		for(j = 0; j < i; j++) {
			if(comInput[i] == comInput[j]) {
				i--;
				break;
			}
		}
	}
	
	while(1) {
		strike = 0;
		ball = 0;
			
		// ���� �Է� 
		printf("[0 ~ 9] ���ڸ� 3�� �Է����ּ���.\n");
		printf(">> ");
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		
		if(input[0] <= 0 || input[0] >= 10 || input[1] <= 0 || input[1] >= 10 || input[2] <= 0 || input[2] >= 10) {
			printf("\n��  ���ڸ� �ٽ� �Է����ּ���.\n\n");
			continue;
		}
		
		// �˼� 
		for(i = 0; i < 3; i++) {
			if(input[i] == comInput[i]) {
				strike++;
			} else {	
				for(j = 0; j < 3; j++) {
					if(input[i] == comInput[j]) {
						ball++;
					}
				}
			}
		}
		
		count++;
		
		printf("\n��  Strike : %d , Ball : %d\n\n", strike, ball);
		
		if(strike == 3) {
			printf(">> %d������ Ŭ�����ϼ̽��ϴ�!\n", count);
			break;
		}
	}

	return 0;
}
