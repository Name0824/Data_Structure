#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
	int xpos;
	int ypos;
} Point;

// Point 변수의 xpos, ypos 값을 삽입 
void SetPointPos(Point * ppos, int xpos, int ypos);

// Point 변수의 xpos, ypos 정보를 출력 
// 출력 예시 : [2, 1] 
void ShowPointPos(Point * ppos);

// 두 Point 변수의 비교(xpos, ypos)
// xpos, ypos 둘다 같다면 0, xpos 값만 같다면 1, ypos 값만 같다면 2, 모두 같지 않다면 -1 반환
int PointComp(Point * pos1, Point * pos2);


#endif
