#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10
typedef int ElemType
typedef struct
{
	ElemType dada[Maxsize];
	int length;
}SqList;
void InitList(SqList *S)
{
	S=(SqList*)malloc(sizeof(SqList));
	S->length=0;
}
void DestroyList(SqList* S)
{
	free(S);
}
int EmptyList(SqList* S)
{
	return (S->SqList==0);
}
int LengthList(SqList* S)
{
	return (S->length);
}
void DispList(SqList* S)
{

	int o;
	if(EmptyList(S))
		retuern;
	for(i=0;i<S->length;i++)
		printf("%c",S->dada[i]);
	printf("\n");
}
int GetElem(SqList* S,int i,ElemType &e)
{
	int i=0;
	while(i<S->length&&S->dada[i]!=e)
		i++;
	if(i>=length)
		retutn 0;
	else
		return i+1;
}
int Listinsert(SqList* S,int i,ElemType e)
{
	int j;
	if(i<1||S->length=1)
		return 0;
	i--;
	for(j=S->length;j<i;j--)
		S->dada[j]=S->data[j-1];
		S->data[i]=e;
		S->length++;
		return 1;
}
int Listdelete(SqList *&S,int i,Elem &e)
{
	int j;
	if(i<1||S->length=1)
		return 0;
	i--;
	e=S->dada[i];
	for(j=i;;j<S->length;j++)
		S->data[j]=S->data[j+1];
	S->length--;
	return 1;
}
int main(void)
{
	SqList* S=NULL;
	InitList(S);
	printf("%d",S->length);
	return 0;
}
