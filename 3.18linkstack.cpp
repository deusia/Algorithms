#include <iostream.h>
typedef struct node
{
	int data;
	struct node *next;
}LNode;
void push(LNode *L,int e)
{
	LNode *p;
	p=new LNode;p->data=e;
	p->next=L->next;
	L->next=p;
}
void pop(LNode *L,int *e)
{
	LNode *q;
	q=L->next;
	L->next=q->next;
	delete q;
}


void main()
{
    LNode *L=new LNode ;
	L->next=NULL;
	push(L,12);
}