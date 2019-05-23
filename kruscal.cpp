#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 11  //������������ֵ
#define MAXM 20  //�ߵĸ��������ֵ
using namespace std; 

struct edge  //��
{
    int u, v, w; //�ߵĶ��㡢Ȩֵ
}edges[MAXM]; //�ߵ�����
bool cmp(edge x,edge y)
{
    if(x.w==y.w)
        return x.w>y.w;
    return x.w<y.w;
}
int parents[]={0,1,2,3,4,5};
int Ancestor(int v)
{
    while(v!=parents[v]) v=parents[v];
	return v;
}
void unionOpt(int u,int v)
{
     int a1=Ancestor(u),a2=Ancestor(v);
	 if(a1!=a2)
		 parents[a2]=a1;
}
void Krucal(edge edges[],int n,int vexNum)//n represents the num of edges
{
	int i=0;int curEdges=0;
	sort(edges,edges+n,cmp);//�Ա߰�Ȩֵ����
	for(;i<n;i++){
		if(Ancestor(edges[i].u)!=Ancestor(edges[i].v))
		{
			curEdges++;
			cout<<"Added edge:"<<edges[i].u<<"  "<<edges[i].v<<endl;
			unionOpt(edges[i].u,edges[i].v);//�����˵�ϲ�
		}
		if(curEdges==vexNum-1)
			break;
	}
}
void DispEdges(edge edges[])
{
     int i=0;
     while(i<6)
	 {cout<<edges[i].u<<"  "<<edges[i].v<<"  "<<edges[i].w<<endl;i++;}
}
void main()
{
	int i=0;
	int arcs[6][3]={{0,1,3},{0,4,2},{1,3,2},{1,2,9},{2,3,1},{3,4,7}};
    while(i<6)
	{edges[i].u=arcs[i][0];edges[i].v=arcs[i][1];edges[i].w=arcs[i][2];i++;}
    //DispEdges(edges);
	Krucal(edges,6,5);
}