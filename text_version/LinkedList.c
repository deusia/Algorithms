#include<stdio.h>
#include<stdlib.h>
#include"defination.c"
typedef int ElementType;

int main(void)
{
	ElementType X;
	struct Node L;
	PtrToNode P;
	P = L;
	printf("Entet five numbers:");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("%d", &X);
		Insert(X, L, P);
	}
	for (int i = 0; i < 5; i++)
	{
		printf("%d", P->Element);
		P = P->Next;
	}
	return 0;
}