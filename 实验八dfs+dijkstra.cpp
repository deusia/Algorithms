#include <iostream>
#include <cstdlib>
using namespace std;
#define Maxsize 10
#define Max  32767
typedef struct 
{
	int n,e;
	char vex[Maxsize];
	int arc[Maxsize][Maxsize];
}AdjMat;
void storeAdjM(int arcs[][5],AdjMat &g,int n,int e)
{
	int i,j;
	g.n=n;g.e=e;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			g.arc[i][j]=arcs[i][j];
}
void DispAdj(AdjMat g)
{
    int i,j;
	for(i=0;i<g.n;i++){
		for(j=0;j<g.n;j++)
			cout<<g.arc[i][j]<<"  ";
		cout<<endl;
	}
}
int visit[Maxsize];
void DFS(AdjMat g,int v)//对图的深度搜索
{
	int i=0;
    visit[v]=1;cout<<v<<" ";
	for(;i<g.n;i++)
	{
		if(g.arc[v][i]<Max && !visit[i])//v能够到达i,并且i没被访问过
			DFS(g,i);
	}
}

void DFS(BiNode *bt)//二叉树对应的深度搜索
{
	if(bt)
	{
		cout<<bt->data<<"  ";
		DFS(bt->lchild);
		DFS(bt->rchild);
	}
}

bool minNodes[Maxsize];//用于标识各点是否被访问过
typedef struct 
{
	int pre;//目前长度的前趋
	int curLen;//当前到源点长度
}Distance;
int minIndex(Distance dist[],int n)//找出暂时没有求出最短路径点到源点的长度中最小的值
{
	int i=0,min=Max,ind=-1;
	for(;i<n;i++)
	   if(!minNodes[i] && dist[i].curLen<min)
		   ind=i;
    return ind;
}

void Dijkstra(AdjMat g,int v)//起点是v,到各个节点的距离
{
	memset(minNodes,0,sizeof(minNodes));
	Distance dist[Maxsize];
	int cur,j;
	int i=0;
	minNodes[v]=1;//初始化
	while(i<g.n)
	{
		dist[i].pre=v;
		dist[i].curLen=g.arc[v][i];i++;
	}
	for(i=1;i<g.n;i++)//还需要加入n-1个节点
	{		
		cur=minIndex(dist,g.n);
		minNodes[cur]=1;
		for(j=0;j<g.n;j++)//cur点的邻接点到达起点的距离会不会变短，如果变短就要更新
			if(!minNodes[j]&& dist[j].curLen>g.arc[cur][j]+dist[cur].curLen)
			{
				//j点到达起点的距离比j点通过cur到达起点的距离要长，这时候要更新j的信息
				dist[j].curLen=g.arc[cur][j]+dist[cur].curLen;
				dist[j].pre=cur;
			}
	} 
	cout<<endl;
	for(i=0;i<g.n;i++)
		printf("\n%d 结点的前趋为 %d,%d结点到达源点的最短路径长度为%d\n",i,dist[i].pre,i,dist[i].curLen);
}
void main()
{
	AdjMat g;
	int arcs[5][5]={{0,3,Max,Max,2},{3,0,9,2,Max},{Max,9,0,1,Max},
				{Max,2,1,0,7},{2,Max,Max,7,0}};
    storeAdjM(arcs,g,5,6);
	DispAdj(g);
    memset(visit,0,sizeof(visit));
	DFS(g,0);
	Dijkstra(g,0);	
}