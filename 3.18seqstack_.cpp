#include "stdio.h"
#include "iostream.h"
#define MaxSize 10
 
typedef struct
{
    int Data[MaxSize];   // �洢Ԫ�ص�����
    int Top;       //ջ��ָ��
}SeqStack;
//return 0 Ϊfalse,1Ϊtrue(��ͬ)
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
//�ж�ջs�Ƿ�Ϊ��
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
    if(s.Top != MaxSize -1)//֮ǰ�Ķ�����������ֵ���±�
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