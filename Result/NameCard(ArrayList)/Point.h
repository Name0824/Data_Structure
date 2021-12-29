#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point {
	int xpos;
	int ypos;
} Point;

// Point ������ xpos, ypos ���� ���� 
void SetPointPos(Point * ppos, int xpos, int ypos);

// Point ������ xpos, ypos ������ ��� 
// ��� ���� : [2, 1] 
void ShowPointPos(Point * ppos);

// �� Point ������ ��(xpos, ypos)
// xpos, ypos �Ѵ� ���ٸ� 0, xpos ���� ���ٸ� 1, ypos ���� ���ٸ� 2, ��� ���� �ʴٸ� -1 ��ȯ
int PointComp(Point * pos1, Point * pos2);


#endif
