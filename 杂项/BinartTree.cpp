#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
}BiNode;
void InOrder(BiNode * bt)
{
	if(bt!=NULL)
	{
		InOrder(bt->lchild);
		cout<<bt->data<<" ";
		InOrder(bt->rchild);
	}
}
void PreOrder(BiNode * bt)
{
	if(bt!=NULL)
	{
		cout<<bt->data<<"  ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
void PostOrder(BiNode * bt)
{
	if(bt!=NULL)
	{
	PostOrder(bt->lchild);
	PostOrder(bt->rchild);
	cout<<bt->data<<"  ";
	}
}
void Create(BiNode *& bt,char data[],int & cur)
{
	if(data[cur]!='\0')
	{
			if(data[cur]=='#')
	        bt=NULL;
			else
			{
				bt=new BiNode;
				bt->data=data[cur];
				Create(bt->lchild,data,++cur);
				Create(bt->rchild,data,++cur);
			}
	}
}
int main(void)
{
	BiNode * bt;
	int cur=0;
	char data[]="ab##cd###";
	Create(bt,data,cur);