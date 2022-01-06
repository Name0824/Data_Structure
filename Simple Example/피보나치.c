#include <stdio.h>

// 피보나치 수열 
// 0 1 1 2 3 5 8 13 21 34 55 . . .
// 첫항인 경우 				0
// 두번째 항인 경우 		1 
// 세번째 이상인 경우 = 전항 + 전전항 
// Fibo(n) = Fibo(n-1) + Fibo(n-2)

int Fibo(int n) {
	if(n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	} else {
		return Fibo(n-1) + Fibo(n-2);
	}
}

int main(void) {
	
	int i;
	
	for(i = 1; i < 15; i++) {
		printf("%d ", Fibo(i));
	}
	
	return 0;
}
