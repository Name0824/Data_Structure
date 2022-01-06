#include <stdio.h>
#include <string.h>

int main(void) {
	char str[] = "Good Morning!";
	

	printf("배열 str의 길이 %d\n", strlen(str));
	printf("배열 str의 크기 %d\n", sizeof(str));
	
	// 문자열의 마지막은 널문자(아스키코드 0, '\0') 
	printf("널 문자 문자형 출력 : %c\n", str[13]);
	printf("널 문자 정수형 출력 : %d\n", str[13]);
	
	// 널 문자를 str 중간에 삽입하면? 
	str[6] = '\0';
	printf("문자열 출력 : %s\n", str);
	
	return 0;
}
