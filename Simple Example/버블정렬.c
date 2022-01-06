#include <stdio.h>
/*
	버블 정렬 (오름 차순) 1 2 3 ->
	7 4 5 1 3	:: 기본 
	4 5 1 3 7	:: 1회 
	4 1 3 5 7	:: 2회 
	1 3 4 5 7	:: 3회 
	1 3 4 5 7	:: 4회 
	
	특징 1 : 버블 정렬을 1회 시도하면 배열에서 가장 큰 수 하나가 오른쪽으로 무조건 지정
	특징 2 : 버블 정렬을 [n - 1] 회 시도하면 오름 차순으로 정렬이 완료 된다. 
*/


// 기존 값이 비교 값보다 크다면, 기존 값을 빈 값에 넣어두고 
// 기존 값에 비교 값을 넣고 비교 값에 기존 값을 넣는다. 
void BubbleSort(int arr[], int n) {
	int i, j, k;
	int temp;
	
	for(i = 0; i < n - 1; i++) {
		printf("[%d 번] ", i);
		
		for(j = 0; j < n; j++) {
			printf("%d ", arr[j]);
		}
		
		printf("\n");
		
		// 뒤에 있는 인덱스 번호는 어차피 큰 값으로 있는 값이므로 계산을 안해도 된다.
		// 그래서 n - j - 1 형식으로 만들어준다. 
		for(k = 0; k < (n-i-1); k++) {
			if(arr[k] > arr[k + 1]) {
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
			}
		}
	}
}

int main(void) {	

	
	int arr[5] = {7, 4, 5, 1, 3};
	
	BubbleSort(arr, sizeof(arr)/sizeof(int));
	
	int i;
	
	printf("\n[버블 정렬] ");
	for(i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	
	
	return 0;
}
