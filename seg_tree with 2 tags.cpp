#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define maxn 100500
#define mid ((ln+rn)>>1)
using namespace std;
int n;
long long p;
struct seg_tree
{
	int mul,add,mi,mx;
	long long sum;
}a[maxn<<2];
inline void read_ll(long long &data)
{
	data=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		data=data*10+ch-48;
		ch=getchar();
	}while(ch>='0'&&ch<='9');
}
inline void read(int &data)
{
	data=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		data=data*10+ch-48;
		ch=getchar();
	}while(ch>='0'&&ch<='9');
}
void write(int data)
{
	if(data>9) write(data/10);
	putchar((data%10)+48);
}
void build(int ln,int rn,int rt)
{
	if(ln==rn) read_ll(a[rt].sum);
	else
	{
		a[rt].mul=1;
		a[rt].add=0;
		build(ln,mid,rt<<1);
		build(mid+1,rn,rt<<1|1);
		a[rt].sum=(a[rt<<1].sum+a[rt<<1|1].sum)%p;
	}
}

inline void pass_down(int rt,int ln,int rn)
{
	if(a[rt].mul==1&&a[rt].add==0) return;
	a[rt<<1].mul=(a[rt<<1].mul*a[rt].mul)%p;
	a[rt<<1|1].mul=(a[rt<<1|1].mul*a[rt].mul)%p;
	a[rt<<1].add=(a[rt<<1].add*a[rt].mul+a[rt].add)%p;
	a[rt<<1|1].add=(a[rt<<1|1].add*a[rt].mul+a[rt].add)%p;
	a[rt<<1].sum=(a[rt<<1].sum*a[rt].mul+a[rt].add*(mid-ln+1))%p;
	a[rt<<1|1].sum=(a[rt<<1|1].sum*a[rt].mul+a[rt].add*(rn-mid))%p;
	a[rt].add=0;
	a[rt].mul=1; 
}
void value_add(int l,int r,int ln,int rn,int rt,int tag)
{
	if(ln>r||rn<l) return;
	if(ln>=l&&rn<=r) 
	{
		a[rt].sum=(a[rt].sum+tag*(rn-ln+1))%p;
		a[rt].add=(a[rt].add+tag)%p;
		return;
	}
	if(ln==rn) return;
	pass_down(rt,ln,rn);
	value_add(l,r,ln,mid,rt<<1,tag);
	value_add(l,r,mid+1,rn,rt<<1|1,tag);
	a[rt].sum=(a[rt<<1].sum+a[rt<<1|1].sum)%p;
}
void value_multiple(int l,int r,int ln,int rn,int rt,int tag)
{
	if(ln>r||rn<l) return;
	if(ln>=l&&rn<=r)
	{
		a[rt].sum=(a[rt].sum*tag)%p;
		a[rt].mul=(a[rt].mul*tag)%p;
		a[rt].add=(a[rt].add*tag)%p;
		return;
	}
	if(ln==rn) return;
	pass_down(rt,ln,rn);
	value_multiple(l,r,ln,mid,rt<<1,tag);
	value_multiple(l,r,mid+1,rn,rt<<1|1,tag);
	a[rt].sum=(a[rt<<1].sum+a[rt<<1|1].sum)%p;
}
long long query(int l,int r,int ln,int rn,int rt)
{
	if(ln>r||rn<l) return 0;
	if(ln>=l&&rn<=r) return a[rt].sum;
	if(ln==rn) return 0;
	pass_down(rt,ln,rn);
	return (query(l,r,ln,mid,rt<<1)+query(l,r,mid+1,rn,rt<<1|1))%p;
}
int main()
{
	memset(a,0,sizeof(a));
	read(n);read_ll(p);
	build(1,n,1);
	int m,q,t,g,c;
	read(m);
	for(int i=1;i<=m;++i)
	{
		read(q),read(t),read(g);
		if(q==1) read(c),value_multiple(t,g,1,n,1,c%p);
		if(q==2) read(c),value_add(t,g,1,n,1,c%p);
		if(q==3) printf("%lld\n",query(t,g,1,n,1));	
	}
	return 0;
}
