#include<stdio.h>
#include <malloc.h>
#include<windows.h>
#define MaxSize 50
#define INCREMENT 10
typedef int ElemType;
typedef struct
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
int SqListInit(SqList *L)
{
	L->elem = (ElemType*)malloc(MaxSize * sizeof(ElemType));
	if (!L->elem) return 0;
	L->length = 0;
	L->listsize = MaxSize;
	return 1;
}
int SqListInsert(SqList *L, int i, ElemType e)
{
	int j;
	ElemType * newbase;
	if (i<1 || i>L->length + 1) return 0;
	if (L->length >= L->listsize)
	{
		newbase = (ElemType *)realloc(L->elem,( L->listsize + INCREMENT) * sizeof(ElemType));
		if (!newbase) return 0;
		L->elem = newbase;
		L->listsize += INCREMENT;
	}
	for (j = L->length - 1; j >= i - 1; j--)
		L->elem[j + 1] = L->elem[j];
		L->elem[i - 1] = e;
	    ++L->length;
	    return 1;
}
int SqListDelete(SqList *L, int i, ElemType *e)
{
	int j;
	if (i<1 || i>L->length) return 0;
	*e = L->elem[i - 1];
	for (j = i - 1; j < L->length - 1; j++)
		L->elem[j] = L->elem[j + 1];
	    --L->length;
		return 1;
} 
int SqListLocate(SqList L, ElemType e)
{
	int i = 1;
	while (i <= L.length&&L.elem[i - 1] != e) i++;
	if (i <= L.length) return 1;
	else return 0;
}
int main()
{
	int i, x, m, e;
	SqList sq;
	SqListInit(&sq);
	for (i = 0; i < 5; i++)
	{
		printf("请输入第%d个元素的值：", i + 1);
		scanf_s("%d", &x);
		SqListInsert(&sq, i + 1, x);
	}
	printf("当前线性表中元素依次为： \n");
	for (i = 0; i < sq.length; i++)
		printf_s("%3d", sq.elem[i]);
	printf("\n 请输入需要插入的元素的位置和值为：");
	scanf_s("%d%d", &m, &x);
	SqListInsert(&sq, m, x);
	printf("插入后线性表的元素为： \n");
	for (i = 0; i < sq.length; i++)
		printf("%3d", sq.elem[i]);
	printf("\n 请输入需要删除的元素的位置：");
		scanf_s("%d", &m);
		SqListDelete(&sq, m, &e);
		printf("删除%d后线性表中的元素依次为： \n", e);
		for (i = 0; i < sq.length; i++)
			printf("%3d", sq.elem[i]);
		printf("\n 请输入需要查找元素的值：");
		scanf_s("%d", &x);
		m = SqListLocate(sq, x);
		if (m > 0)
			printf("%d是线性表第%d个元素 \n", x, m);
		else
			printf("链表中没有此元素 \n");
		system("pause");
		return 0;
}