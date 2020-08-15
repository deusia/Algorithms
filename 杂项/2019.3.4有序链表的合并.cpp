#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{
	int data;
	struct node * next;
}LNode,*LinkList;
void CreateList(LinkList &L, int d[],int n)
{
	int i = 0; LNode *p;
	L = new LNode; p = L;
	while (i<n)
	{
		p->next = new LNode; p = p->next; p->data = d[i]; i++;
	}
	p->next = NULL;
}
void DispList(LinkList  L)
{
	LNode *p=L->next;
	while (p)
	{		cout << p->data << '\t'; p = p->next;	}
	cout << endl;
}
void MergeList(LinkList  La, LinkList  Lb, LinkList  &Lc)
{
	LNode *pa, *pb, *pc;
	pa = La->next; pb = Lb->next; Lc = pc = La;
	while (pa && pb){
		if (pa->data<pb->data)
		{			pc->next = pa; pc = pc->next; pa = pa->next;		}
		else
		{			pc->next = pb; pc = pc->next; pb = pb->next;		}
	}
	pc->next = pa ? pa : pb;
}
void main()
{ 
	LinkList La, Lb,Lc;
	int da[] = { 1, 3, 4, 6 }, db[] = { 2, 7, 9 };
	CreateList(La, da, 4); DispList(La);
	CreateList(Lb, db, 3); DispList(Lb);
	MergeList(La, Lb, Lc); DispList(Lc);
	system("pause");
}