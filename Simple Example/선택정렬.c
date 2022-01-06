#include <stdio.h>

// 9, 6, 7, 3, 5 	초기값 
// 3, 6, 7, 9, 5 	1회 
// 3, 5, 7, 9, 6	2회 
// 3, 5, 6, 9, 7	3회 
// 3, 5, 6, 7, 9	4회 

// 배열의 처음 부터 끝까지 탐색 -> 최솟값 탐색 
// 찾은 최솟값은 첫번째 위치에 배정시킵니다.
// 배정이 끝났으면 두번째 위치부터 탐색 시작.
// 위와 같은 방법으로 n-1번 반복 
 
void SelectionSort(int arr[], int n) {
	int i, j, k;
	int temp, minIdx;
	
	for(i = 0; i < (n - 1); i++) {
		minIdx = i;
		
		printf("[%d 번] ", i);
		
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
	
	printf("\n[선택 정렬] ");
	for(i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	
	
	return 0;
}
