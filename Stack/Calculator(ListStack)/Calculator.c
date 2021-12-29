// 후위 표기법 계산 소스 파일 

#include <stdio.h>		// 입출력 관련 
#include <ctype.h>		// 숫자인지, 문자인지 

#include "ListStack.h"
#include "Calculator.h"

Data CalcPostfix(char exp[]) {
	Stack stack;
	S_Init(&stack);
	
	Data opr1, opr2;
	int i, value, k = 0;
	
	for(i = 0; exp[i] != '\0'; i++) {
		if(isdigit(exp[i])) {
		// 문자가 숫자인지 아닌지 확인 ( 0 ~ 9 ) 
			// 공백이 아니라면 k 값 상승 
			while(exp[i + k] != ' ') {
				k++;
			}
			
			// 문자를 정수로 바꿔주는 함수 atoi 사용 
			// 공백이 나온다면 거기까지만 정수 변환 ( "100 20 300" => 100 ) 
			S_Push(&stack, atoi(&exp[i]));
			
			// i 값을 공백이 위치한 장소로 점프 
			i += k;
			// k 의 값은 다시 0으로 만들어준다. 
			k = 0;
		} else {
			// 공백이라면 넘긴다. 
			if(exp[i] == ' ') continue;
			
			// 스택에 있는 숫자를 빼서 각 변수에 넣어줌, 변수 순서에 주의 
			opr2 = S_Pop(&stack);
			opr1 = S_Pop(&stack);
			
			// 연산자에 따른 계산 
			switch(exp[i]) {
				case '+': S_Push(&stack, opr1 + opr2); break;
				case '-': S_Push(&stack, opr1 - opr2); break;
				case '*': S_Push(&stack, opr1 * opr2); break;
				case '/': S_Push(&stack, opr1 / opr2); break;
			}
		}
	}
	
	// 마지막으로 스택에 있는 값을 리턴 
	return S_Pop(&stack);
}
