#include<iostream>
using namespace std;
#define MaxSize 10
typedef struct
{
	char vex[MaxSize];
	int arcs[MaxSize][MaxSize];
	int n,e;
}AdjMat;
void StoreToMat(char vex[],int arcs[][5],AdjMat &g,int n)
{
	int i,j;
	strcpy_s(g.vex,vex);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)	
			g.arcs[i][j]=arcs[i][j];
		g.n=n;
}
void DispMat(AdjMat g)
{
	int i,j;
	for(i=0;i<g.n;i++)
	{
		for(j=0;j<g.n;j++)
			cout<<g.arcs[i][j]<<"  ";
	cout<<endl;
	}
}
int visit[MaxSize];
void DFS(AdjMat g,int v)
{
	int i;
	visit[v]=1;
	cout<<v<<"  ";
	for (i=0;i<g.n;i++)
		if(!visit[i] && g.arcs[v][i])
			DFS(g,i);
}
int main(void)
{
	AdjMat g;
	char vex[]="abcde";
	int arcs[][5]=
	{
		{0,1,1,1,1},
	    {1,0,1,0,0},
		{1,1,0,1,0},
		{1,0,1,0,1},
		{1,0,0,1,0}
	};
	StoreToMat(vex,arcs,g,5);
	DispMat(g);
	memset(visit,0,sizeof(visit));	
	cout<<"DFS result is:"<<endl;
	DFS(g,0);
	cout<<endl;
}