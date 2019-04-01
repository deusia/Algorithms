#include<iostream>
using namespace std;
#define Maxsize 10
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}LNode;
void InitList(LNode* &L)
{
	L=new LNode;
	L->data=0;
	L->next=NULL;
}
void HeadInsertList(LNode* L,ElemType e)
{
	LNode* p=new LNode;
	p->data=e;
	p->next=L->next;
	L->next=p;
}
void DispList(LNode* L)
{
	LNode* p=L->next;
	while(p)  
	{
		cout<<p->data<<'\t';
		p=p->next;
	}
	cout<<endl;
}
LNode* SearchList(LNode* L,ElemType e)
{
	LNode* p=L->next;
	while(p)
	{
		if(e==p->data)
			return p;
		else
			p=p->next;
	}
	return p;                                //p is NULL
}
void DelList(LNode* L,ElemType e)
{
	LNode* p=L;
	LNode* q;
	while(p->next)
	{
		if(p->next->data==e)
		{
			q=p->next;
			p->next=q->next;
			delete q;
			break;
		}
		else p=p->next;	
	}
}
void InvertList(LNode* L)
{
	LNode* p;
	LNode* q;
	p=L->next;
	q=p->next;
	while(!p)
	{
		p->next=L->next;
		L->next=p;
		p=q;
		if(!q)
			q=q->next;
	}
}

int main(void)
{
	LNode* L,*p;
	InitList(L);
	HeadInsertList(L,81);
	HeadInsertList(L,79);
	HeadInsertList(L,34);
	HeadInsertList(L,112);
	DispList(L);
	p=SearchList(L,34);
		if(p)
			cout<<"Find it!"<<p->data<<endl;
		else
			cout<<"Not find!"<<endl;
		DelList(L,34);
		DispList(L);
}

