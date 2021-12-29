//#include <stdio.h>
//#include <stdlib.h>
//#include "CLinkedList.h"
//
//int exam_main(void) {
//	List list; // ����ü ����Ʈ ���� ���� 
//	Data data; // ���� ��� �ٲ�� ���Կ� ������ ���� ���� 
//	
//	ListInit(&list); // ����Ʈ �ʱ�ȭ 
//	
//	// LInsert�� �̿��� 6~10���� �����͸� �Է����ּ���.
//	// LInsertFront�� �̿��ؼ� 1~5���� �����͸� �Է����ּ���.
//	// �����ʹ� ������������ ���ĵ˴ϴ�. 
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
//	// �����͸� 30ȸ �������� ������ּ���. 
//	// ���� ���Ḯ��Ʈ�� ������ ������ ���� �����ͷ� �ٽ� ù��° �����͸� ��ȸ�մϴ�.
//	// LNext�� �̿��� 30ȸ �������� ������ּ���, for �Ǵ� while ������ �̿밡���մϴ�.
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
//	// 2�� ����� ã�Ƽ� ��� �����մϴ�.
//	// �������� ũ��� LCount �Լ��� �̿��մϴ�.
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
//	// ��ü ������ 1ȸ ��� 
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
