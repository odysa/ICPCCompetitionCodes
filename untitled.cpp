#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<fstream>
#define maxn 1000000002
using namespace std;
int h,t;
int k,b;
int px,py;
struct point
{
	int E=0;
	int S=0;
}T[50010][50010];
struct o1
{
	int x;
	int y;
	int vis=0;
	int pre;
}q[50010];
int a[50010];
inline void read()
{
	px=0,py=0;
	char c=getchar();
	while(c=='E'||c=='S')
	{
		if(c=='S') T[px++][py].S=-1;
		else T[px][py++].E=-1;
		c=getchar();
	}
	return;
}
inline void output()
{
	int cnt=0,tp,xx,yy,tl=tail;
	while(xx!=0&&yy!=0)
	{
		tp=q[tl].pre;
		xx=q[tp].x;
		yy=q[tp].y;
		if(xx==q[tl]) a[++cnt]=1;
		else a[++cnt]=0; 
	}
	for(int i=cnt;i>=1;--i)
	{
		if(a[i]) printf("E");
		else printf("S");
	}
}
inline void BFS()
{
	int tx,ty;
	head=0,tail=0;
	q[head].x=0,q[head].y=0,q[head].vis=-1;
	while(head<=tail)
	{
		q[head].vis=-1;
		tx=q[head].x,ty=q[head].y;
		if(tx==n-1&&ty==n-1)
		{
			output();
			return;
		}
		if(!T[tx][ty].E) q[++tail].x=tx,q[tail].y=ty+1,q[tail].pre=head;
		if(!T[tx][ty].S) q[++tail].x=x+1,q[tail].y=y,q[tail].pre=head;
		++head;
	}
	return;
}
inline ini()
{
	for(int i=0;i<=n*n;++i) q[iq.pre=[i].x=q[i].y=q[i].vis=0;
	for(int i=0;i<=n;++i)
	 for(int j=0;j<=n;++j)
	 {
	 	T[i][j].E=T[i][j].S=0
	 }
}
int main()
{
	int num=1;
	scanf("%d",&k);
	while(num<=k)
	{
		x=0,y=0;
		scanf("%d",&n);

		++num;
		read();

	}
	return 0; 
}