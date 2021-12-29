#include <stdio.h>		// 입출력 	관련 
#include <stdlib.h>		// 동적할당 관련 

#include "ListBaseStack.h"

// 정의 
#define PATH		0		// 지나갈 수 있는 길 
#define WALL		1		// 지나갈 수 없는 길 
#define VISITED		2		// 이미 방문한 길 
#define BACKTRACKED	3		// 방문 했다 되돌아 온 길 

// 미로 관련  
#define MAZE_SIZE	10
#define FILE_NAME	"miro.txt"
char maze[MAZE_SIZE][MAZE_SIZE];

/*
미로 파일 작성방법 
:: 10 * 10 크기로 작성 

0 = 길 	 , 1 = 벽 
5 = 입구 , 9 = 출구 
*/

// 시작점 지정 
Data startMaze(Data cur) {
	int i, j;
	
	for(i = 0; i < MAZE_SIZE; i++) {
		for(j = 0; j < MAZE_SIZE; j++) {
			if(maze[i][j] == 5) {
				cur.x = i;
				cur.y = j;
				
				return cur;
			}
		}
	}
	
	printf("시작점이 존재하지 않습니다.\n");
	printf("\n");
	system("pause");
	exit(-1);
}

// 미로 출력 
void printMaze() {
	int i, j;
	
	for(i = 0; i < MAZE_SIZE; i++) {
		for(j = 0; j < MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}
		
		printf("\n");
	}
}

// 북, 동, 남, 서 체크 
int offset[4][2] = {
	{-1, 0},	// 북쪽 : 0
	{0 , 1},	// 동쪽 : 1
	{1 , 0},	// 남쪽 : 2
	{0, -1}		// 서쪽 : 3
};

// 이동 [0, 1, 2, 3]
Data move(Data cur, int dir) {
	cur.x += offset[dir][0];
	cur.y += offset[dir][1];
	
	return cur;
}

// 이동하기전 체크 
int moveCheck(Data cur, int dir) {
	cur = move(cur, dir);
	
	// cur.x , cur.y 가 음수인 경우 
	// cur.x , cur.y 가 미로 크기 - 1 을 넘는 경우 
	if(cur.x < 0 || cur.y < 0 || cur.x > MAZE_SIZE - 1 || cur.y > MAZE_SIZE - 1) {
		return 0;
	}
	
	// 길이 있거나 출구가 있는 경우 
	if(maze[cur.x][cur.y] == PATH || maze[cur.x][cur.y] == 9) {
		return 1;
	} else {
		return 0;
	}
}

int main(void) {
	Stack stack;
	StackInit(&stack);
	Data cur;
	
	int i, j, n;
	int dir, count = 0;
	
	// 미로 파일 읽기 
	FILE * fp = fopen(FILE_NAME, "r");
	
	if(fp == NULL) {
		printf("파일 오픈 에러 !");
		exit(-1);
	} 

	for(i = 0; i < MAZE_SIZE; i++) {
		for(j = 0; j < MAZE_SIZE; j++) {
			fscanf(fp, "%d", &n);
			maze[i][j] = n;
		}
	}
	
	// 미로 파일 닫기 
	fclose(fp);

	// 시작점 세팅 
	cur = startMaze(cur);
	
	printf("시작점 : [%d, %d]\n\n", cur.x, cur.y);
	
	// 탈출 시작 
	while(1) {
		if(maze[cur.x][cur.y] == 9) {
			printf("\n << 탈출 성공 >> \n");
			break;
		}
		
		// 방문 했거나, 되돌아온 길이면 
		if(maze[cur.x][cur.y] == VISITED || maze[cur.x][cur.y] == BACKTRACKED) {
			maze[cur.x][cur.y] = BACKTRACKED;
		} else {
			maze[cur.x][cur.y] = VISITED;
		}

		int foward = 0; // 스위치 변수 
		
		// 갈 곳이 있는 상황 
		for(dir = 0; dir < 4; dir++) {
			if(moveCheck(cur, dir)) {
				SPush(&stack, cur);
				cur = move(cur, dir);
				foward = 1;
				
				break;
			}
		}
		
		//갈 곳이 없는 상황 
		if(foward == 0) {
			if(SIsEmpty(&stack)) {
				printf("출구가 존재하지 않습니다.\n");
				break;
			}
			
			maze[cur.x][cur.y] = BACKTRACKED;
			cur = SPop(&stack);
		}
		
	}
	
	printMaze();
	
	printf("\n");
	system("pause");
	
	return 0;
}
