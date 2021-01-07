#pragma once
#include <stdio.h>
#include <stdlib.h>
#define Stack_Size 100
#define TRUE 1
#define FALSE 0

typedef struct
{
	double elem[Stack_Size];
	int top;
}DoubleStack;

typedef struct
{
	char elem[Stack_Size];
	int top;
}CharStack;

void InitStack(DoubleStack* S);
void InitStack(CharStack* S);
int Push(DoubleStack* S, double x);
int Push(CharStack* S, char x);
int Pop(DoubleStack* S, double* x);
int Pop(CharStack* S, char* x);
int GetTop(DoubleStack* S, double* x);
int GetTop(CharStack* S, char* x);
bool IsEmpty(DoubleStack* S);
bool IsEmpty(CharStack* S);

void BracketMatch(char* str); 
bool Match(char left, char right);

void PostfixConvert(char* str, char* exp);
int Compare(char a, char b);
void Append(char* str, char ch);

double PostfixEvaluation(char* exp);
double Execute(double a, char oprt, double b);