#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

int main(void) {
	List list;
	ListInit(&list);
	Data data;
	
	int i;
	for(i = 8; i >= 1; i--) {
		LInsert(&list, i);
	}
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	printf("\n\n");
	
	int n = 0;
	
	if(LFirst(&list, &data)) {
		printf("%d ", data);
		
		while(LNext(&list, &data)) {
			if(n == 3) {
				break;
			}
			
			printf("%d ", data);
			
			n++;
		}
		
		printf("<- ");
		
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
		
		printf("-> ");
		
		while(LNext(&list, &data)) {
			printf("%d ", data);
		}
		
		printf("<- ");
		
		while(LPrevious(&list, &data)) {
			printf("%d ", data);
		}
	}
	
	return 0;
}
