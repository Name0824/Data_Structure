//#include <stdio.h>
//#include <stdlib.h>
//#include "CLinkedList.h"
//
//int exam_main(void) {
//	List list; // 구조체 리스트 변수 선언 
//	Data data; // 값이 계속 바뀌는 삽입용 데이터 변수 선언 
//	
//	ListInit(&list); // 리스트 초기화 
//	
//	// LInsert를 이용해 6~10까지 데이터를 입력해주세요.
//	// LInsertFront를 이용해서 1~5까지 데이터를 입력해주세요.
//	// 데이터는 오름차순으로 정렬됩니다. 
//	// 1, 2, 3, 4 ... 9, 10
//
//	int i;
//	
//	for(i = 6; i <= 10; i++) {
//		LInsert(&list, i);
//	}
//	
//	for(i = 5; i >= 1; i--) {
//		LInsertFront(&list, i);
//	}
//
//	// 데이터를 30회 연속으로 출력해주세요. 
//	// 원형 연결리스트는 마지막 데이터 다음 데이터로 다시 첫번째 데이터를 순회합니다.
//	// LNext를 이용해 30회 연속으로 출력해주세요, for 또는 while 문으로 이용가능합니다.
//	// 1 ~ 10, 1 ~ 10, 1 ~ 10
//
//	i = 1;
//	
//	if(LFirst(&list, &data)) {
//		printf("%d ", data);
//		
//		while(LNext(&list, &data)) {
//			if(i % 10 == 0) {
//				printf("\n");
//			}
//			
//			if(i == 30) {
//				break;
//			}
//			
//			printf("%d ", data);
//			
//			i++;
//		}
//	}
//	
//	// 2의 배수를 찾아서 모두 삭제합니다.
//	// 데이터의 크기는 LCount 함수를 이용합니다.
//	
//	int size = LCount(&list);
//	
//	if(LFirst(&list, &data)) {
//		if(data % 2 == 0) {
//			LRemove(&list);
//		}
//
//		for(i = 1; i < size; i++) {
//			LNext(&list, &data);
//			if(data % 2 == 0) {
//				LRemove(&list);
//			}
//		}
//	}
//	
//	// 전체 데이터 1회 출력 
//	
//	size = LCount(&list);
//	
//	if(LFirst(&list, &data)) {
//		printf("%d ", data);
//
//		for(i = 1; i < size; i++) {
//			LNext(&list, &data);
//			printf("%d ", data);
//		}
//	}
//	 
//	return 0;
//}
