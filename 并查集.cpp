#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int f[1000];
int n,m,k,sum;
inline void pre()
{
	int x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) f[i]=i;
	for(int i=1;i<=n;++i) 
	{
		scanf("%d%d",&x,&y);
		f[x]=y;
	}
	return;
}
inline int getf(int x)
{
	int p=x,t;
	while(f[x]!=x) x=f[x];
	while(x!=p)
	{
		t=f[p];
		f[p]=x;
		p=t;
	}
	return x;
}
inline void combine(int a,int b)
{
	int x1=getf(a);
	int x2=getf(b);
	if(x1!=x2) f[x2]=x1;
	return;
}
int main()
{
	pre();
	printf("%d",getf(3));
	return 0;	
}
