#include <stdio.h>

// ����Լ� 
void Recursive(int num) {
	if(num <= 0) return;	// �Լ� ���� ���ǽ� 
	
	printf("Recursive Number : %d\n", num);
	Recursive(num - 1);		// ���� �ڵ� ���� 
}

int main(void) {
	
	Recursive(5);
	
	return 0;
}
