#include <stdio.h>
#include <stdlib.h>
#include <time.h>	// Ÿ�� �Լ� 

#include "ListBaseQueue.h"

// �ܹ��� ���Կ��� 1�ð����� �ֹ��� �����鼭 ������ �Ѵٸ� ��� �ֹ��� ó���� �� ������? 

#define CUSTOMER_TERM 30	// 30�ʸ��� �ֹ� 

#define CHE_BUR		0	// ġ�� ���� 
#define BUL_BUR		1	// �Ұ�� ���� 
#define DUB_BUR		2	// ���� ���� 

#define CHE_TERM	45	// ġ�� ���� ���� �ð� 
#define BUL_TERM	60	// �Ұ�� ���� ���� �ð� 
#define DUB_TERM	80	// ���� ���� ���� �ð� 


int main(void) {
	Queue q;
	QueueInit(&q);
	 
	int sec;										// �ð��� ���� 
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;	// �ֹ� �� 
	int cheMade = 0, bulMade = 0, dubMade = 0;		// ������� �� 
	
	int makeProc = 0;	// ���� �ð� 
	
	// ������ �߻��Ǵ� seed ���� �����ϴ� �Լ� �⺻ �� (1) 
	srand(time(NULL));
	
	// 60 �� = 3600 �� 
	for(sec = 0; sec < 3600; sec++) {
		// �ֹ� �ð��� ���� ��� 
		if(sec % CUSTOMER_TERM == 0) {
			// 3���� ���� �ֹ��� �޴´� 
			switch(rand() % 3) { 
				case CHE_BUR:	// ġ�� ���� 
					Enqueue(&q, CHE_TERM);	// ť�� ġ�� ���� �����ð� ���� 
					cheOrder++;				// ġ�� ���� �ֹ��� + 1 
					break;
				case BUL_BUR:	// �Ұ�� ���� 
					Enqueue(&q, BUL_TERM);
					bulOrder++;
					break;
				case DUB_BUR:	// ���� ���� 
					Enqueue(&q, DUB_TERM);
					dubOrder++;
					break;
			}
		}
		
		// �ֹ��� ���� �� 
		// ������ �� �� �����̸�  ť�� ��� ���� �ʴٸ� 
		if(makeProc <= 0 && !QIsEmpty(&q)) {
			makeProc = Dequeue(&q);	// �����ð� 
			
			switch(makeProc) {
				case CHE_TERM:	// ġ�� ���� �����ð� 
					cheMade++;	// ġ�� ���� ���� �Ϸ� + 1 
					break;
				case BUL_TERM:	// �Ұ�� ���� �����ð� 
					bulMade++;
					break;
				case DUB_TERM:	// ���� ���� �����ð� 
					dubMade++;
					break;
			}
		}
		
		makeProc--;	// ���� ���� �����ð� -1 
	}
	
	printf("============ ��׳� ����Ʈ ============\n");
	printf("ġ����� �ֹ��� : %d, ���� �ֹ� ó���� : %d\n", cheOrder, cheMade);
	printf("�Ұ����� �ֹ��� : %d, ���� �ֹ� ó���� : %d\n", bulOrder, bulMade);
	printf("������� �ֹ��� : %d, ���� �ֹ� ó���� : %d\n", dubOrder, dubMade);
	
	return 0;
}
