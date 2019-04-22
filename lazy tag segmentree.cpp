#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define maxn 400000
#define lson l,r,ln,mid,rt<<1
#define rson l,r,mid+1,rn,rt<<1|1
using namespace std;
long long sum[maxn+2],delta[maxn+2];
inline void update(int l,int r,int rt)
{
	int mid=(l+r)>>1;
	sum[rt<<1]+=delta[rt]*(mid-l+1);
	delta[rt<<1]+=delta[rt];
	sum[rt<<1|1]+=delta[rt]*(r-mid);
	delta[rt<<1|1]+=delta[rt];
	delta[rt]=0;
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	return;
}
void build(int l,int r,int rt)
{
	if(l==r) 
	{
		scanf("%d",&sum[rt]);
		return;
	}
	else
	{
		int mid=(l+r)>>1;
		build(l,mid,rt<<1);
		build(mid+1,r,rt<<1|1);
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
	return;
}
void change(int l,int r,int ln,int rn,int rt,int tag)
{
	if(l<=ln&&r>=rn)
	{
		sum[rt]+=tag*(rn-ln+1);
		delta[rt]+=tag;
	}
	else
	{
		if(delta[rt]!=0) update(ln,rn,rt);
		int mid=(ln+rn)>>1;
		if(l<=mid) change(lson,tag);
		if(r>mid)  change(rson,tag);
		sum[rt]=sum[rt<<1]+sum[rt<<1|1]; 
	}
}
long long query(int l,int r,int ln,int rn,int rt)
{
	if(l<=ln&&r>=rn)
	{
		return sum[rt];
	}
	else
	{
		if(delta[rt]!=0) update(ln,rn,rt);
		long long ans=0;
		int mid=(ln+rn)>>1;
		if(l<=mid) ans+=query(lson);
		if(r>mid)  ans+=query(rson);
		return ans;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	build(1,n,1);
	int t,x,y,k;
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&t);
		if(t==1) scanf("%d%d%d",&x,&y,&k),change(x,y,1,n,1,k);
		if(t==2) scanf("%d%d",&x,&y),printf("%lld\n",query(x,y,1,n,1));
	}
	return 0;
}
