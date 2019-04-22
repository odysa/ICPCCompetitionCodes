#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct edge
{
	int u;
	int v;
	int w;
}t[1000];
bool cmp(struct edge a,struct edge b){return a.w<b.w;}
int n,m,sum=0,ans=0;
int f[100],nxt[1000],fst[1000];
inline void read(int &x)
{
	char ch=getchar();
	x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		x=x*10+ch-48;
		ch=getchar();
	}while(ch>='0'&&ch<='9');
}
inline int getf(int x)
{
	int p=x,t;
	while(x!=f[x]) x=f[x];
	while(x!=p)
	{
		t=f[p];
		f[p]=x;
		p=t;
	}
	return x;
}
inline int combine(int a,int b)
{
	int x1=getf(a);
	int x2=getf(b);
	if(x1!=x2)
	{
		f[x1]=x2;
		return 1;
	}
	else return 0;
}
inline void pre()
{
	for(int i=1;i<=n;++i)  f[i]=i;
	for(int i=1;i<=m;++i) fst[i]=-1;
	read(n),read(m);
	for(int i=1;i<=m;++i) read(t[i].u),read(t[i].v),read(t[i].w);
}
inline void operate()
{
	sort(t,t+n+1,cmp);
	for(int i=1;i<=m;++i)
	{
		if(combine(t[i].u,t[i].v))
		{
			++sum;
			ans+=t[i].w;
		}
		if(sum==m-1) break;
	}
}
inline void output()
{
	printf("%d\n",ans);
}
int main()
{
	pre();
	operate();
	output(); 
	return 0;
}
