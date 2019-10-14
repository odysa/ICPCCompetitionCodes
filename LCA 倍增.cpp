#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxn 1000010
using namespace std;
inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		x=x*10+ch-48;
		ch=getchar();
	} while(ch>='0'&&ch<='9');
}
struct edge
{
	int to,nxt;
}e[maxn];
int tot=0;
int head[maxn];
int n,m,rt,f[maxn][20],deep[maxn],t;
inline void add(int x,int y)
{
	e[++tot].to=y;
	e[tot].nxt=head[x];
	head[x]=tot;
}
void build(int rt)
{ 
	for(int i=head[rt];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if(!deep[v])
		{
			deep[v]=deep[rt]+1;
			f[v][0]=rt;
			build(v);
		}
	}
}
inline void pre()
{
	for(int j=1;j<=19;++j)
	 for(int i=1;i<=n;++i)
	 {
	 	f[i][j]=f[f[i][j-1]][j-1];
	 }
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int LCA(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=19;i>=0;--i)
	{
		if(deep[f[x][i]]>=deep[y]) x=f[x][i];
	}
	if(x==y) return y;
	for(int i=19;i>=0;--i)
	if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0]; 
}
int main()
{
	memset(head,-1,sizeof(head));
	int a,b;
	read(n),read(m),read(rt);
	for(int i=1;i<=n-1;++i)
	{
		read(a),read(b);
		add(a,b);	
		add(b,a);
	}
	deep[rt]=1;
	build(rt);
	pre();
	for(int i=1;i<=m;++i)
	{
		read(a),read(b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
} 
