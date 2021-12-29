#include <stdio.h>		// ����� 	���� 
#include <stdlib.h>		// �����Ҵ� ���� 

#include "ListBaseStack.h"

// ���� 
#define PATH		0		// ������ �� �ִ� �� 
#define WALL		1		// ������ �� ���� �� 
#define VISITED		2		// �̹� �湮�� �� 
#define BACKTRACKED	3		// �湮 �ߴ� �ǵ��� �� �� 

// �̷� ����  
#define MAZE_SIZE	10
#define FILE_NAME	"miro.txt"
char maze[MAZE_SIZE][MAZE_SIZE];

/*
�̷� ���� �ۼ���� 
:: 10 * 10 ũ��� �ۼ� 

0 = �� 	 , 1 = �� 
5 = �Ա� , 9 = �ⱸ 
*/

// ������ ���� 
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
	
	printf("�������� �������� �ʽ��ϴ�.\n");
	printf("\n");
	system("pause");
	exit(-1);
}

// �̷� ��� 
void printMaze() {
	int i, j;
	
	for(i = 0; i < MAZE_SIZE; i++) {
		for(j = 0; j < MAZE_SIZE; j++) {
			printf("%d ", maze[i][j]);
		}
		
		printf("\n");
	}
}

// ��, ��, ��, �� üũ 
int offset[4][2] = {
	{-1, 0},	// ���� : 0
	{0 , 1},	// ���� : 1
	{1 , 0},	// ���� : 2
	{0, -1}		// ���� : 3
};

// �̵� [0, 1, 2, 3]
Data move(Data cur, int dir) {
	cur.x += offset[dir][0];
	cur.y += offset[dir][1];
	
	return cur;
}

// �̵��ϱ��� üũ 
int moveCheck(Data cur, int dir) {
	cur = move(cur, dir);
	
	// cur.x , cur.y �� ������ ��� 
	// cur.x , cur.y �� �̷� ũ�� - 1 �� �Ѵ� ��� 
	if(cur.x < 0 || cur.y < 0 || cur.x > MAZE_SIZE - 1 || cur.y > MAZE_SIZE - 1) {
		return 0;
	}
	
	// ���� �ְų� �ⱸ�� �ִ� ��� 
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
	
	// �̷� ���� �б� 
	FILE * fp = fopen(FILE_NAME, "r");
	
	if(fp == NULL) {
		printf("���� ���� ���� !");
		exit(-1);
	} 

	for(i = 0; i < MAZE_SIZE; i++) {
		for(j = 0; j < MAZE_SIZE; j++) {
			fscanf(fp, "%d", &n);
			maze[i][j] = n;
		}
	}
	
	// �̷� ���� �ݱ� 
	fclose(fp);

	// ������ ���� 
	cur = startMaze(cur);
	
	printf("������ : [%d, %d]\n\n", cur.x, cur.y);
	
	// Ż�� ���� 
	while(1) {
		if(maze[cur.x][cur.y] == 9) {
			printf("\n << Ż�� ���� >> \n");
			break;
		}
		
		// �湮 �߰ų�, �ǵ��ƿ� ���̸� 
		if(maze[cur.x][cur.y] == VISITED || maze[cur.x][cur.y] == BACKTRACKED) {
			maze[cur.x][cur.y] = BACKTRACKED;
		} else {
			maze[cur.x][cur.y] = VISITED;
		}

		int foward = 0; // ����ġ ���� 
		
		// �� ���� �ִ� ��Ȳ 
		for(dir = 0; dir < 4; dir++) {
			if(moveCheck(cur, dir)) {
				SPush(&stack, cur);
				cur = move(cur, dir);
				foward = 1;
				
				break;
			}
		}
		
		//�� ���� ���� ��Ȳ 
		if(foward == 0) {
			if(SIsEmpty(&stack)) {
				printf("�ⱸ�� �������� �ʽ��ϴ�.\n");
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
