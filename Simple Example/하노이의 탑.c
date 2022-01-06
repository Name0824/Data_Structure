#include <stdio.h>

// 하노이의 탑 
// 절대 값을 추적할 수 없음 
// 재귀함수를 이해한다는 것은 완벽한 조건 로직을 걸어놓고 컴퓨터에게 시키는 것 
// 반복 패턴을 명확하게 이해하고 그에 맞는 조건을 기획하고 재귀적으로 코드를 작성 

// 조건 
// 시작점, 서브지점, 도착점 
// 1. 큰 원반을 제외한 n-1개의 원반을 시작점에서 서브지점으로 이동 
// 2. 큰 원반을 시작점에서 도착점으로 이동 
// 3. (n-1)개의 원반을 서브에서(시작점이 서브가 됨) 도착점으로 이동 
// 4. 원반이 1개일때 num이 1일때는 2번 조건 적용 

void hanoi(int num, char A, char B, char C) {
	if(num == 1) {
		printf("> 원반 %d는 %c에서 %c로 이동\n", num, A, C);
	} else {
		hanoi(num-1, A, C, B);
		printf(">> 원반 %d는 %c에서 %c로 이동\n", num, A, C);
		hanoi(num-1, B, A, C);
	}
}

int main(void) {
	int i;
	
	hanoi(3, 'A', 'B', 'C');
	
	return 0;
}
