#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define maxn 132456
#define inf 2147483647
using namespace std;
int nxt[maxn],fst[maxn];
int u[maxn],v[maxn],w[maxn];
int dis[maxn],book[maxn],loc[maxn];
int t,n,m,mi;
class min_heap
{
	public:
		int size;
		int h[maxn];
	public:
		inline void siftdown(int i);
		inline void siftup(int i);
		inline int top();
		inline void push(int x);
		inline void  dellmin();
}q;
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
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline int min_heap::top(){return h[1];}
inline void min_heap::siftdown(int i)
{
	int t,flag=0;
	while((i<<1)<=size&&flag==0)
	{
		t=h[i<<1]<h[i]?i<<1:i;
		if(i<<1|1<=size) t=h[t]>h[i<<1|1]?i<<1|1:t;
		if(t!=i) swap(h[i],h[t]),i=t;
		else flag=1;
	}
}
inline void min_heap::siftup(int i)
{
	int flag=0;
	while(i!=1&&flag==0)
	{
		if(h[i]<h[i>>1]) swap(h[i],h[i>>1]);
		else flag=1;
		i>>=1;
	}
}
inline void min_heap::push(int x){h[++size]=x; siftup(size);}
inline void pre()
{
	memset(book,0,sizeof(book));
	book[1]=1;
	read(n),read(m);
	for(int i=1;i<=n;++i) 
	fst[i]=-1,loc[i]=i,dis[i]=inf;
	dis[1]=0;
	for(int i=1;i<=m;++i)
	{
		read(u[i]),read(v[i]),read(w[i]);
		if(u[i]==1) dis[v[i]]=w[i];
		nxt[i]=fst[u[i]];
		fst[u[i]]=i;
	}
}
inline void operate()
{
	for(int i=1;i<=n-1;++i)
	{
		mi=inf;
		for(int j=1;j<=n;++j)
		{
			if(book[j]==0&&dis[j]<mi)
			mi=dis[j],t=j;
		}
		book[t]=1;
		int k=fst[t];
		while(k!=-1)
		{
			dis[v[k]]=dis[v[k]]>(dis[t]+w[k])?dis[t]+w[k]:dis[v[k]];
			k=nxt[k];
		}
	}
}
inline void output()
{
	for(int i=1;i<=n;++i) printf("%d\n",dis[i]);
}
int main()
{
	pre();
	operate();
	output();
	return 0;
	
}
