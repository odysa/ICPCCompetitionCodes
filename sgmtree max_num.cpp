#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 200001
#define inf 2147483647
using namespace std;
int h[maxn<<2],len=0,d,t;
inline int max(const int &a,const int &b){return a>b?a:b;}
inline void read(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		x=x*10+ch-48;
		ch=getchar();
	}while(ch>='0'&&ch<='9');
}
void write(int x)
{
	int flag=0;
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar((x%10)+48);
}
void build(int l,int r,int rt)
{
	if(l==r) return;
	else
	{
		h[rt]=-inf;
		int mid=(l+r)>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
	}
}
void update(int r,int ln,int rn,int rt,int tag)
{
	if(ln==rn){h[rt]=tag;return;}
	else
	{
		int mid=(ln+rn)>>1;
		if(r<=mid) update(r,ln,mid,rt<<1,tag);
		else update(r,mid+1,rn,rt<<1|1,tag);
		h[rt]=max(h[rt<<1],h[rt<<1|1]);
	}
}
int query(int l,int r,int ln,int rn,int rt)
{
	if(ln>=l&&rn<=r) return h[rt];
	else
	{
		int mid=(ln+rn)>>1;
		int ans=-inf;
		if(l<=mid) ans=query(l,r,ln,mid,rt<<1);
		if(r>mid) ans=max(ans,query(l,r,mid+1,rn,rt<<1|1));
		return ans;
	}
}
int main()
{
	int m,k;
	char ch;
	build(1,maxn,1);
	read(m);read(d);
	for(int i=1;i<=m;++i)
	{
		cin>>ch;
		if(ch=='A') read(k),++len,update(len,1,maxn,1,(k+t)%d);
		else if(ch=='Q')read(k),t=query(len-k+1,len,1,maxn,1),printf("%d\n",t);
	}	
	return 0;
}
