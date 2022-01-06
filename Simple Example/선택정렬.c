#include <stdio.h>

// 9, 6, 7, 3, 5 	�ʱⰪ 
// 3, 6, 7, 9, 5 	1ȸ 
// 3, 5, 7, 9, 6	2ȸ 
// 3, 5, 6, 9, 7	3ȸ 
// 3, 5, 6, 7, 9	4ȸ 

// �迭�� ó�� ���� ������ Ž�� -> �ּڰ� Ž�� 
// ã�� �ּڰ��� ù��° ��ġ�� ������ŵ�ϴ�.
// ������ �������� �ι�° ��ġ���� Ž�� ����.
// ���� ���� ������� n-1�� �ݺ� 
 
void SelectionSort(int arr[], int n) {
	int i, j, k;
	int temp, minIdx;
	
	for(i = 0; i < (n - 1); i++) {
		minIdx = i;
		
		printf("[%d ��] ", i);
		
		for(j = 0; j < n; j++) {
			printf("%d ", arr[j]);
		}
		
		printf("\n");
		
		for(k = (1 + i); k < n; k++) {
			if(arr[minIdx] > arr[k]) {
				minIdx = k;
			}
		}
		
		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

int main(void) {	

	
	int arr[5] = {9, 6, 7, 3, 5};
	
	SelectionSort(arr, sizeof(arr)/sizeof(int));
	
	int i;
	
	printf("\n[���� ����] ");
	for(i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	
	
	return 0;
}
