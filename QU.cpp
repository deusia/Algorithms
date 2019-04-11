#include<iostream>
using namespace std;
typedef int ElemType;
typedef struct node
{
	ElemType data;
	struct node* next;
}QNode;
typedef struct
{
	QNode* front;
	QNode* rear;
}QHead;
void InitQu(QHead *&qh)
{
	qh=new QHead;
	qh->front=qh->rear=new QNode;
	qh->rear->next=NULL;
}
void EnQu(QHead* qh,ElemType e)
{
	QNode* p=new QNode;
	p->data=e;
	p->next=NULL;
	qh->rear->next=p;
	qh->rear=p;
}
void DeQu(QHead* qh,ElemType &e)
{
    QNode* p;
    if(qh->front==qh->rear)
       return;
    p=qh->front->next;
    e=p->data;
    if(qh->rear==p)
    qh->rear=qh->front;
    qh->front->next=p->next;
    delete p;
}
void DispQu(QHead* qh)
{
	QNode* p=qh->front->next;
	while(p)
	{
		cout<<p->data<<"   ";
		p=p->next;
	}
}

int main(void)
{
	QHead* qh;
	//ElemType e;
	InitQu(qh);
	EnQu(qh,3);
	EnQu(qh,5);
	EnQu(qh,7);
	EnQu(qh,9);
	DispQu(qh);
}
