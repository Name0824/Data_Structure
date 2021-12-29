// 후위 표기법 계산기 헤더 파일 

#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

// 계산 전 문법 검사 
int SyntaxSearch(char exp[]);

// 후위 표기법 변환 
void ConvToPostfix(char exp[]);

// 후위 표기법 계산 
Data CalcPostfix(char exp[]);

#endif
