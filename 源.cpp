#include<stdio.h>
#include<windows.h>
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
int SqListInsert(SqList*, int, ElemType);
void SqListEmpty(SqList*);
void SqListDelete(SqList*, int, ElemType*);
int SqListLocate(SqList*, ElemType);
void SqListPrint(SqList*);
int main(void)
{
	int e;
	SqList* L;
	SqList p;
	L = &p;
	SqListInit(L);
	printf("length=%d\nlistsize=%d\n", L->length, L->listsize);
	for (int i = 0; i < 5; i++)
	{
		printf("Enter NO.%d number:",i+1);
		scanf_s("%d", &e);
		SqListInsert(L, i + 1, e);
	}
	for (int i = 0; i < 5; i++)
		printf("%5d", p.Elem[i]);
	
	
	system("pause");
	return 0;

}
int SqListInit(SqList* L)
{
	L->Elem = (ElemType*)malloc(MaxSize*sizeof(ElemType));
	if (!L->Elem)        //  check the return value is not
		return 0;       //     NULL  !!!!!!!!!!

	L->length = 0;
	L->listsize = MaxSize;
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

	for (j = L->length - 1; j >= i - 1; j--)
		L->Elem[j] = L->Elem[j + 1];
	L->Elem[i - 1] = e;
	++L->length;
	return 1;
}
void SqListDelete(SqList* L, int i, ElemType *e)
{
	int j;
	*e = L->Elem[i - 1];
	for (j = i - 1; i < L->length; i++)
		L->Elem[i] = L->Elem[i + 1];
	--L->length;
	
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
void SqListPrint(SqList* L)
{
	int i;
	for (i = 0; i < L->length; i++)
		printf("%5d", L->Elem[i]);
}