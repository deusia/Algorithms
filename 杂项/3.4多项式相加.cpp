#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct node
{
	int coef,index;
	struct node * next;
}LNode,*LinkList;
void CreateList(LinkList &L, int d[],int n)
{
	int i = 0; LNode *p;
	L = new LNode; p = L;
	while (i<n)
	{
		p->next = new LNode; p = p->next; p->coef = d[i++];p->index=d[i++];
	}
	p->next = NULL;
}
void DispList(LinkList  L)
{
	LNode *p=L->next;
	while (p)
	{		cout << p->coef << "  " << p->index << '\t'; p = p->next;	}
	cout << endl;
}
void MergeList(LinkList  La, LinkList  Lb, LinkList  &Lc)
{
	LNode *pa, *pb, *pc;
	pa = La->next; pb = Lb->next; Lc = pc = La;
	while (pa && pb){
		if (pa->index<pb->index)
		{			pc->next = pa; pc = pc->next; pa = pa->next;		}
		else if (pa->index>pb->index)
		{			pc->next = pb; pc = pc->next; pb = pb->next;		}
		else
		{
			if (pa->coef == pb->coef) { pa = pa->next; pb = pb->next;  }
			else
			{
				pc->next = pa; pa->coef = pa->coef + pb->coef; pa = pa->next; pb = pb->next;
			}
		}
	}
	pc->next = pa ? pa : pb;
}
void main()
{ 
	LinkList La, Lb,Lc;
	int da[] = { 1, 0,3,1,-2 ,4,9, 6 }, db[] = {1, 2, 2,4, 12,9 };
	CreateList(La, da, 8); DispList(La);
	CreateList(Lb, db, 6); DispList(Lb);
	MergeList(La, Lb, Lc); DispList(Lc);
	system("pause");
}