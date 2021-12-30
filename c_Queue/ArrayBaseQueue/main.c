#include <stdio.h>		// 입출력 
#include <stdlib.h>		// 동적할당 

#include "ArrayBaseQueue.h"

int main(void) {
	Queue q;
	QueueInit(&q);
	
	printf(">> 입력 >> ");
	Enqueue(&q, 'A');
	Enqueue(&q, 'B');
	Enqueue(&q, 'C');
	Enqueue(&q, 'D');
	printf("\n>> 갯수 >> %d\n", getCount(&q));

	printf(">> 출력 >> ");
	while(!QIsEmpty(&q)) {
		printf("[%c] ", Dequeue(&q));
	}
	
	printf("\n\n");
	
	printf(">> 입력 >> ");
	Enqueue(&q, 'A');
	Enqueue(&q, 'B');
	Enqueue(&q, 'C');
	Enqueue(&q, 'D');
	printf("\n>> 갯수 >> %d\n", getCount(&q));

	printf(">> 출력 >> ");
	while(!QIsEmpty(&q)) {
		printf("[%c] ", Dequeue(&q));
	}
	
	printf("\n\n");
	
	printf(">> 입력 >> ");
	Enqueue(&q, 'A');
	Enqueue(&q, 'B');
	Enqueue(&q, 'C');
	Enqueue(&q, 'D');
	printf("\n>> 갯수 >> %d\n", getCount(&q));

	printf(">> 출력 >> ");
	while(!QIsEmpty(&q)) {
		printf("[%c] ", Dequeue(&q));
	}
	
	return 0;
}
