#include <iostream.h>
typedef struct node
{
	int data;
	struct node* next;
}LNode;
void dispLList(LNode *L)
{
	LNode *p=L;
    while(p)
	{cout<<p->data<<'\t';
	p=p->next;}

	cout<<endl;
}
void insertList(LNode *L,int i,int e)
{
	LNode *p=L,*q;int j=1;
	while(j<i && p){p=p->next;j++;}
    if (p)
    {
		q=new LNode;
		q->data=e;
		q->next=p->next;p->next=q;
    }
	else
		cout<<"pos error!"<<endl;
}
void delList(LNode *L,int i,int *e)
{
	LNode *p=L,*q;int j=1;
    while(j<i && p){p=p->next;j++;}
	if (p)
    {
	   q=p->next;
	   *e=q->data;
	   p->next=q->next;
	   delete q;
    }
	else
		cout<<"pos error!"<<endl;
}
void reverseList(LNode *L)
{
	LNode *q,*p=L->next;
	L->next=NULL;
	while(p)
	{
	   q=p->next;
	   p->next=L->next;
	   L->next=p;
	   p=q;
	}
	
}
void createLList(LNode *L)
{
	LNode *p=L,*q;int i;
	cin>>i;
	while(i!=-1)
	{
		q=new LNode;q->data=i;
		p->next=q;p=q;
		cin>>i;
	}
	p->next=NULL;

}
void main()
{ 
    LNode *L;//int delelem;
	L=new LNode;
	createLList(L);
	dispLList(L->next);
	//insertList(L,3,101);
    //dispLList(L->next);
    //delList(L,2,&delelem);
	reverseList(L);
	dispLList(L->next);
	//cout<<delelem;
}