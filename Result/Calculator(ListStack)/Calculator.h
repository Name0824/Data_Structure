// ���� ǥ��� ���� ��� ���� 

#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

// ��� �� ���� �˻� 
int SyntaxSearch(char exp[]);

// ���� ǥ��� ��ȯ 
void ConvToPostfix(char exp[]);

// ���� ǥ��� ��� 
Data CalcPostfix(char exp[]);

#endif
