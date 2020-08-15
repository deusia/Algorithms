#include<iostream>
using namespace std;
#define MaxSize 10
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SeqStack;
void InitStack(SeqStack* &s)
{
	s=new SeqStack;
	s->top=-1;
}
bool InsertStack(SeqStack* s,ElemType e)
{
	if(s->top==MaxSize-1)
		return 0;
	s->top++;
	s->data[s->top]=e;
	return 1;
}
ElemType GetTop(SeqStack* s)//get the top element
{
	if(s->top==-1)
		return 0xffffffff;
	return s->data[s->top];
}
bool Pop(SeqStack* s,ElemType* e)
{
	if(s->top==-1)
		return 0;
	*e=s->data[s->top];
	s->top--;
	return 1;
}
int main(void)
{
	ElemType e;
	SeqStack* s;
	InitStack(s);
	InsertStack(s,34);
	InsertStack(s,45);
	InsertStack(s,87);
	InsertStack(s,32);
	Pop(s,&e);
	cout<<e<<endl;
	e=GetTop(s);
	cout<<e<<endl;
									
}