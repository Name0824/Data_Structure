#include <stdio.h>

// 재귀함수 
void Recursive(int num) {
	if(num <= 0) return;	// 함수 종료 조건식 
	
	printf("Recursive Number : %d\n", num);
	Recursive(num - 1);		// 증감 코드 구현 
}

int main(void) {
	
	Recursive(5);
	
	return 0;
}
