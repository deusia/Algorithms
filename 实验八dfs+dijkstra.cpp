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
void DFS(AdjMat g,int v)//��ͼ���������
{
	int i=0;
    visit[v]=1;cout<<v<<" ";
	for(;i<g.n;i++)
	{
		if(g.arc[v][i]<Max && !visit[i])//v�ܹ�����i,����iû�����ʹ�
			DFS(g,i);
	}
}

void DFS(BiNode *bt)//��������Ӧ���������
{
	if(bt)
	{
		cout<<bt->data<<"  ";
		DFS(bt->lchild);
		DFS(bt->rchild);
	}
}

bool minNodes[Maxsize];//���ڱ�ʶ�����Ƿ񱻷��ʹ�
typedef struct 
{
	int pre;//Ŀǰ���ȵ�ǰ��
	int curLen;//��ǰ��Դ�㳤��
}Distance;
int minIndex(Distance dist[],int n)//�ҳ���ʱû��������·���㵽Դ��ĳ�������С��ֵ
{
	int i=0,min=Max,ind=-1;
	for(;i<n;i++)
	   if(!minNodes[i] && dist[i].curLen<min)
		   ind=i;
    return ind;
}

void Dijkstra(AdjMat g,int v)//�����v,�������ڵ�ľ���
{
	memset(minNodes,0,sizeof(minNodes));
	Distance dist[Maxsize];
	int cur,j;
	int i=0;
	minNodes[v]=1;//��ʼ��
	while(i<g.n)
	{
		dist[i].pre=v;
		dist[i].curLen=g.arc[v][i];i++;
	}
	for(i=1;i<g.n;i++)//����Ҫ����n-1���ڵ�
	{		
		cur=minIndex(dist,g.n);
		minNodes[cur]=1;
		for(j=0;j<g.n;j++)//cur����ڽӵ㵽�����ľ���᲻���̣������̾�Ҫ����
			if(!minNodes[j]&& dist[j].curLen>g.arc[cur][j]+dist[cur].curLen)
			{
				//j�㵽�����ľ����j��ͨ��cur�������ľ���Ҫ������ʱ��Ҫ����j����Ϣ
				dist[j].curLen=g.arc[cur][j]+dist[cur].curLen;
				dist[j].pre=cur;
			}
	} 
	cout<<endl;
	for(i=0;i<g.n;i++)
		printf("\n%d ����ǰ��Ϊ %d,%d��㵽��Դ������·������Ϊ%d\n",i,dist[i].pre,i,dist[i].curLen);
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