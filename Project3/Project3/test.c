#include<stdio.h>
#include<stdlib.h>
#include"defination.h"
int main(void)
{
	struct Node N;
	List L = &N;
	Position P = &N;
	ElementType X;
	Initilize(L);
	printf("%d", L->Element);
		return 0;
}