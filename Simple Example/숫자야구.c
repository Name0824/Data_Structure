#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));	// 난수 시드 값 
	
	int input[3], comInput[3];
	
	int strike, ball, count = 0;
	int i, j;
	
	// 컴퓨터 입력 
	for(i = 0; i < 3; i++) {
		comInput[i] = rand() % 10;
		
		// 중복 값이면 값 재정의 
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
			
		// 유저 입력 
		printf("[0 ~ 9] 숫자를 3개 입력해주세요.\n");
		printf(">> ");
		scanf("%d %d %d", &input[0], &input[1], &input[2]);
		
		if(input[0] <= 0 || input[0] >= 10 || input[1] <= 0 || input[1] >= 10 || input[2] <= 0 || input[2] >= 10) {
			printf("\n▶  숫자를 다시 입력해주세요.\n\n");
			continue;
		}
		
		// 검수 
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
		
		printf("\n▶  Strike : %d , Ball : %d\n\n", strike, ball);
		
		if(strike == 3) {
			printf(">> %d번만에 클리어하셨습니다!\n", count);
			break;
		}
	}

	return 0;
}
