#include"L.h"
#include<stdlib.h>
#include"fatal.h"
typedef int ElementType;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
	ElementType Element;
	Position Next;
};
/*return true if L is empty*/
int IsEmpty(List L)
{
	return L->Next == NULL;
}
/*return true if P is the last position in list L*/
/*Parameter L is unused in this implementation*/
int IsLast(Position P,List L)
{
	return P->Next == NULL;
}
/*return position of X in List;NULL if not found*/
Position Find(ElementType X, List L)
{
	Position P;

	P = L->Next;

	while (P && P->Element != X)
		P = P->Next;

	return P;
}
/*Delete first occurrence of X from a list*/
/*Assume use of a header node*/
void Delete(ElementType X, List L)
{
	Position P, TempCell;
	P = dd(X, L); 
	if (!IsLast(P, L))
	{
		TempCell = P->Next;
		P->Next = TempCell->Next;
		free(TempCell);
	}
}
//If X  is not find ,then return next field of returned
//position is NULL
//assume a header
Position dd(ElementType X, List L)
{
	Position P;
	P = L;

	if (P->Next->Element != X && P->Next != NULL);
	P = P->Next;

	return P;
}
/*Insert (after a legal position P)*/
//header implementation assumed
//parameter L is unused in this implemetation
void Insert(ElementType X, List L, Position P)
{
	Position TempCell;

	TempCell = (PtrToNode)malloc(sizeof(struct Node));
	if (TempCell == NULL)
		FatalError("out of space!!!");
	TempCell->Element = X;
	TempCell->Next= P->Next;
	P->Next = TempCell;
}
void DeleteList(List L)
{
	Position P,Temp;
	P = L->Next;
	L->Next = NULL;
	while (P != NULL)
	{
		Temp = P->Next;
		free(P);
		P = Temp;
	}
}
//free the initial List and then make a new one
List MakeEmpty(List L)
{
	if (L != NULL)
		DeleteList(L);
	L = (PtrToNode)malloc(sizeof(struct Node));
	if(L==NULL)
		FatalError("Out of memory!");
	L->Next = NULL;
	return L;
}
//return to the head of the List
Position Header(List L)
{
	return L;
}
//return to the first element of its List
Position First(List L)
{
	return L->Next;
}
/*Get the element of its position*/
ElementType Retrieve(Position P)
{
	return P->Element;
}