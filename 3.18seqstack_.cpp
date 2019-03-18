#include "stdio.h"
#include "iostream.h"
#define MaxSize 10
 
typedef struct
{
    int Data[MaxSize];   // 存储元素的数组
    int Top;       //栈顶指针
}SeqStack;
//return 0 为false,1为true(下同)
int Pop(SeqStack &L)
{
    if(L.Top == 0)
    {
        return 0;
    }
    printf("%d ",L.Data[--L.Top]);
    return 1;
}
int Push(SeqStack &L, int e)
{
    if(L.Top==MaxSize -1)
    {
        return 0;
    }
    L.Data[++L.Top] = e;
    return 1;
}
//判断栈s是否为空
int isEmpty(SeqStack s)
{
    if(s.Top != -1)
    {
        return 1;
    }
    return 0;
}
bool isFull(SeqStack s)
{
    if(s.Top != MaxSize -1)//之前的定义数组的最大值的下标
    {
        return 1;
    }
    return 0;
} 
int  getTop(SeqStack s)
{
	if(s.Top == -1)
        return 0;
	else
         return s.Data[s.Top];
    
}
void main()
{
	SeqStack s;
	s.Top=-1;
	Push(s,10);Push(s,12);Push(s,15);Push(s,21);
	cout<<getTop(s);
}