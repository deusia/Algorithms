#include<stdio.h>
#include<stdlib.h>
#define MaxSize 100
#define INCRETMENT 10
typedef int ElemType;
typedef struct book
{
	ElemType* Elem;
	int length;
	int listsize;
}SqList;
int SqListInit(SqList*);
int SqListInsert(SqList*,int,ElemType);
int SqListEmpty(SqList*)?///////////////
int SqListDelete(SqList*, int, ElemType*);
int SqListLocate(SqList*, ElemType);
int SqListPrint(SqList*);
int main(void)
{
	SqList* L;
	SqList p;
	L=&p;
	if (SqListInit(L))
		printf("%d", L->length);
	else
		printf("Space allocation failed.");

}
int SqListInit(SqList* L)
{
	L->Elem = (ElemType*)malloc(sizeof(ElemType));
	if (!L)        //  check the return value is not
		return 0;  //     NULL  !!!!!!!!!!

		L->length = 0;
		L->listsize;
		return 1;

}
//the function is designed to initialize the struct.
int SqListInsert(SqList* L, int i, ElemType e)
{
	ElemType* newbase;
	int j;
	if (i<1 || i>L->length + 1)
		return 0;

	if (L->length >= L->listsize)
	{
		newbase = (ElemType*)realloc(L->Elem, (L->listsize + INCRETMENT) * sizeof(ElemType));
		if (!newbase)
			return 0;
		L->Elem = newbase;
		L->listsize += INCRETMENT;
	}

	for (j = L->length - 1; j >= i-1; j--)
		L->Elem[j] = L->Elem[j + 1];
	L->Elem[i - 1] = e;
	++L->length;
	return 1;
}
int SqListDelete(SqList* L, int i, ElemType *e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return 0;
	*e = L->Elem[i - 1];
	for (j = i - 1; i < L->length; i++)
		L->Elem[i] = L->Elem[i+1];
	--L->length;
	return ;
}
int SqListLocate(SqList* L, ElemType e)
{
	int i = 1;
	while (i < L->length&&L->Elem[i] != e)
		i++;
	if (i <= L->length)
		return i;
	else
		return 0;
}
int SqListPrint(SqList* L)
{
	if (!L)
		return 0;              //Unable to find the SqList
	int i;
	for (i = 0; i < L->length ; i++)
		printf("%5d", L->Elem[i]);
	return 1;
}
