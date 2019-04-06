#include<stdlib.h>
#include"list.h"
Position FindPrevious(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Next->Element != X)
		P = P->Next;
	return P;
}
void DeleteList(List L)
{
	Position P, Temp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Temp = P->Next;
		free(P);
		P = Temp;
	}
}
void Initilize(List L)
{
	L->Element = 0;
	L -> Next = NULL;
}
List MakeEmpty(List L)
{
	if (L != NULL)
		DeleteList(L);

	L = (struct Node*)malloc(sizeof(struct Node));
	if (L == NULL)
		return NULL;
	L->Element = 0;
	L->Next = NULL;
	return L;
}
int IsEmpty(List L)
{
	return L->Next ==NULL;
}
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}
void Delete(ElementType X, List L)
{
	Position P,Temp;
	P = (Position)FindPrevious(X, L);
	Temp = P->Next->Next;
	if (!IsLast(P, L))
	{
		Temp = P->Next;
		P->Next = Temp->Next;
		free(Temp);
	}
}
void Insert(ElementType X, List L, Position P)
{
	Position Temp;

	Temp = (struct Node*)malloc(sizeof(struct Node));
	if (Temp == NULL)
	return;

	Temp->Element = X;
	Temp->Next = P->Next;
	P->Next = Temp;
}
Position Header(List L)
{
	return L;
}
Position First(List L)
{
	return L->Next;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
