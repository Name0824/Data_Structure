#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "Good Morning!";
	

	printf("�迭 str�� ���� %d\n", strlen(str));
	printf("�迭 str�� ũ�� %d\n", sizeof(str));
	
	// ���ڿ��� �������� �ι���(�ƽ�Ű�ڵ� 0, '\0') 
	printf("�� ���� ������ ��� : %c\n", str[13]);
	printf("�� ���� ������ ��� : %d\n", str[13]);
	
	// �� ���ڸ� str �߰��� �����ϸ�? 
	str[6] = '\0';
	printf("���ڿ� ��� : %s\n", str);
	
	return 0;
}
