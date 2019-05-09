#include<iostream>
using namespace std;
typedef char ElemType;
typedef struct node
{
	ElemType data;
	struct node * lchild;
	struct node * rchild;
}BiNode;
char ch[10]="ab#c##d##";
int pos=0;
void PreOrder(BiNode * bt)
{
	if(bt)
	{
		cout<<bt->data<<"  ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
void InOrder(BiNode * bt)
{
	if(bt)
	{
		InOrder(bt->lchild);
		cout<<bt->data<<"  ";
		InOrder(bt->rchild);
	}
}
void PostOrder(BiNode * bt)
{
	if(bt)
	{
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout<<bt->data<<"  ";
	}
}
void CreateBiTree(BiNode * &bt)
{
	if(ch[pos]!='\0')
	{
		if(ch[pos]!='#')
		{
			bt=new BiNode;
			if(!bt)
				exit(1);
			bt->data=ch[pos++];
			CreateBiTree(bt->lchild);
			CreateBiTree(bt->rchild);
		}
		else
		{
			bt=NULL;
			pos++;
		}
	}
}
int BiTreeHeight(BiNode * bt)
{
	int sl,sr;
	if(!bt)
		return 0;
	sl=BiTreeHeight(bt->lchild);
	sr=BiTreeHeight(bt->rchild);
	return sl>sr?sl+1:sl+1;
}
int TreeNodes(BiNode * bt)
{
	int nl,nr;
	if(!bt)
		return 0;
	if(!bt->lchild&&!bt->rchild)
		return 1;
	else
	{
		nl=TreeNodes(bt->lchild);
		nr=TreeNodes(bt->rchild);
		return nl+nr;
	}
}
int main(void)
{
	BiNode * bt;
	CreateBiTree(bt);
	PreOrder(bt);
	cout<<"the number of the tree "<<TreeNodes(bt)<<endl;
}