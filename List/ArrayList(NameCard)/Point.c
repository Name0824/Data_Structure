#include <stdio.h>
#include "Point.h"

// Point ������ xpos, ypos �� ���� 
void SetPointPos(Point * ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

// point ������ xpos, ypos ���� ��� 
void ShowPointPos(Point * ppos)
{
	printf("[%d, %d]\n", ppos->xpos, ppos->ypos);
}

// �� point ������ �� 
// xpos, ypos �Ѵ� ���ٸ� 0, xpos ���� ���ٸ� 1, ypos ���� ���ٸ� 2, ��� ���� �ʴٸ� -1 ��ȯ 
int PointComp(Point * pos1, Point * pos2)
{
	if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos) {
		return 0;
	} else if(pos1->xpos == pos2->xpos) {
		return 1;
	} else if(pos1->ypos == pos2->ypos) {
		return 2;
	} else {
		return -1;
	}
}
