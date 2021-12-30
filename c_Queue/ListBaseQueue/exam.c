#include <stdio.h>
#include <stdlib.h>
#include <time.h>	// 타임 함수 

#include "ListBaseQueue.h"

// 햄버거 가게에서 1시간동안 주문을 받으면서 조리를 한다면 몇개의 주문을 처리할 수 있을까? 

#define CUSTOMER_TERM 30	// 30초마다 주문 

#define CHE_BUR		0	// 치즈 버거 
#define BUL_BUR		1	// 불고기 버거 
#define DUB_BUR		2	// 더블 버거 

#define CHE_TERM	45	// 치즈 버거 조리 시간 
#define BUL_TERM	60	// 불고기 버거 조리 시간 
#define DUB_TERM	80	// 더블 버거 조리 시간 


int main(void) {
	Queue q;
	QueueInit(&q);
	 
	int sec;										// 시간초 변수 
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;	// 주문 수 
	int cheMade = 0, bulMade = 0, dubMade = 0;		// 만들어진 수 
	
	int makeProc = 0;	// 조리 시간 
	
	// 난수에 발생되는 seed 값을 지정하는 함수 기본 값 (1) 
	srand(time(NULL));
	
	// 60 분 = 3600 초 
	for(sec = 0; sec < 3600; sec++) {
		// 주문 시간이 됐을 경우 
		if(sec % CUSTOMER_TERM == 0) {
			// 3개중 랜덤 주문을 받는다 
			switch(rand() % 3) { 
				case CHE_BUR:	// 치즈 버거 
					Enqueue(&q, CHE_TERM);	// 큐에 치즈 버거 조리시간 삽입 
					cheOrder++;				// 치즈 버거 주문량 + 1 
					break;
				case BUL_BUR:	// 불고기 버거 
					Enqueue(&q, BUL_TERM);
					bulOrder++;
					break;
				case DUB_BUR:	// 더블 버거 
					Enqueue(&q, DUB_TERM);
					dubOrder++;
					break;
			}
		}
		
		// 주문을 받은 후 
		// 조리가 다 된 상태이며  큐가 비어 있지 않다면 
		if(makeProc <= 0 && !QIsEmpty(&q)) {
			makeProc = Dequeue(&q);	// 조리시간 
			
			switch(makeProc) {
				case CHE_TERM:	// 치즈 버거 조리시간 
					cheMade++;	// 치즈 버거 조리 완료 + 1 
					break;
				case BUL_TERM:	// 불고기 버거 조리시간 
					bulMade++;
					break;
				case DUB_TERM:	// 더블 버거 조리시간 
					dubMade++;
					break;
			}
		}
		
		makeProc--;	// 매초 마다 조리시간 -1 
	}
	
	printf("============ 브그낑 리포트 ============\n");
	printf("치즈버거 주문량 : %d, 실제 주문 처리량 : %d\n", cheOrder, cheMade);
	printf("불고기버거 주문량 : %d, 실제 주문 처리량 : %d\n", bulOrder, bulMade);
	printf("더블버거 주문량 : %d, 실제 주문 처리량 : %d\n", dubOrder, dubMade);
	
	return 0;
}
