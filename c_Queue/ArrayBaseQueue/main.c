#include <stdio.h>		// ����� 
#include <stdlib.h>		// �����Ҵ� 

#include "ArrayBaseQueue.h"

int main(void) {
	Queue q;
	QueueInit(&q);
	
	printf(">> �Է� >> ");
	Enqueue(&q, 'A');
	Enqueue(&q, 'B');
	Enqueue(&q, 'C');
	Enqueue(&q, 'D');
	printf("\n>> ���� >> %d\n", getCount(&q));

	printf(">> ��� >> ");
	while(!QIsEmpty(&q)) {
		printf("[%c] ", Dequeue(&q));
	}
	
	printf("\n\n");
	
	printf(">> �Է� >> ");
	Enqueue(&q, 'A');
	Enqueue(&q, 'B');
	Enqueue(&q, 'C');
	Enqueue(&q, 'D');
	printf("\n>> ���� >> %d\n", getCount(&q));

	printf(">> ��� >> ");
	while(!QIsEmpty(&q)) {
		printf("[%c] ", Dequeue(&q));
	}
	
	printf("\n\n");
	
	printf(">> �Է� >> ");
	Enqueue(&q, 'A');
	Enqueue(&q, 'B');
	Enqueue(&q, 'C');
	Enqueue(&q, 'D');
	printf("\n>> ���� >> %d\n", getCount(&q));

	printf(">> ��� >> ");
	while(!QIsEmpty(&q)) {
		printf("[%c] ", Dequeue(&q));
	}
	
	return 0;
}
