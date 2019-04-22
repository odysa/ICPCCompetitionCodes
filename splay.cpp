#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<algorithm>
#define maxn 3000
using namespace std;
struct splay_tree
{
	int f,l,r;
}a[maxn];
inline void read(int &data)
{
	char ch=getchar();
	data=0;
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		data=data*10+ch-48;
		ch=getchar();
	}while(ch>='0'&&ch<='9');
	return ;
}
void write(int data)
{
	if(data>9) write(data);
	putchar((data%10)+48);
	return;
}
inline void zag(int k)
{
	int tmp=a[k].f;
	a[tmp].r=a[k].l;
	if(a[k].l!=-1) a[a[k].l].f=tmp;
	a[k].f=a[tmp].f;
	if(a[tmp].f!=-1)
	{
		if(tmp==a[a[tmp].f].l) a[a[tmp].f].l=k;
		else a[a[tmp].f].r=k;
	}
	a[tmp].f=k;
	a[k].l=tmp;
	return;
}
inline void zig(int k)
{
	int tmp=a[k].f;
	a[tmp].l=a[k].r;
	if(a[k].r!=-1) a[a[k].r].f=tmp;
	a[k].f=a[tmp].f;
	if(a[tmp].f!=-1)
	{
		if(tmp==a[a[tmp].f].l) a[a[tmp].f].l=k;
		else a[a[tmp].f].r=k;
	}
	a[tmp].f=k;
	a[k].r=tmp;
}
inline void splay(int k)
{
	int p;
	while(a[k].f!=-1)
	{
		p=a[k].f;
		if(a[p].f==-1)
		{
			if(k==a[p].l) zig(k);
			else  zag(k);
			break;
		}
	}
}
int main()
{
	memset(a,-1,sizeof(a));
}
