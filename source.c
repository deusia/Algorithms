#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
	ElemType data;
	struct Node * next;
}QNode;
typedef struct
{
    QNode * front;
	QNode * rear;
}LinkQueue;

int InitQueue(LinkQueue *Q)
{
	Q->front=Q->rear=(QNode*)malloc(sizeof(QNode));
	if(Q->front==NULL)
		return 0;
	Q->front->next=NULL;
	return 1;
}

int EnQueue(LinkQueue * Q, ElemType e)
{
	QNode *p;
	p=(QNode*)malloc(sizeof(QNode));
	if(p==NULL)
		return 0;
	Q->rear->next=p;
	Q->rear=Q->rear->next;
	Q->rear->data=e;
	Q->rear->next=NULL;
	return 1;
}
int DeQueue(LinkQueue * Q, ElemType * e)
{
	QNode * p;
	if(Q->front==Q->rear)
		return 0;
	*e=Q->front->next->data;
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->front==p)
		Q->front=Q->rear;
	free(p);
	return 1;
}
void OutputQueue(LinkQueue * head)
{
	while(head->front!=head->rear)
	{
		head->front=head->front->next;
		printf("%5d",head->front->data);
	}
}
int main(void)
{
	ElemType * e;
	LinkQueue Q;
	InitQueue(&Q);
	EnQueue(&Q,6);
	EnQueue(&Q,4);
	EnQueue(&Q,3);
	EnQueue(&Q,8);
	DeQueue(&Q,&e);
	DeQueue(&Q,&e);
	OutputQueue(&Q);




}

