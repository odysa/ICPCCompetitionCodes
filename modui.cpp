#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cmath>
#define maxn 100000
#define size 1000010
using namespace std;
int tmp;
struct node
{
	int l,r,id;
	friend bool operator < (node a,node b){ return a.l/tmp==b.l/tmp?a.r<b.r:a.l<b.l;}
}query[size];
int cnt[size],ans[size],a[size],ANS=0;
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
inline void remove(int pos)
{
	if(--cnt[a[pos]]==0) --ANS;
}
inline void add(int pos)
{
	if(++cnt[a[pos]]==1) ++ANS;
}
int main()
{
		int n,m;
		read(n);
		tmp=sqrt(n);
		for(register int i=1;i<=n;++i) read(a[i]);
		read(m);
		for(register int i=1;i<=m;++i)
		{
			read(query[i].l);
			read(query[i].r);
			query[i].id=i;		
		}
		sort(query+1,query+m+1);
		int curL=0,curR=0;
		int l,r,id;
		for(register int i=1;i<=m;++i)
		{
			l=query[i].l,r=query[i].r,id=query[i].id;
			while(curL<l) remove(curL++);
			while(curR>r) remove(curR--);
			while(curL>l) add(--curL);
			while(curR<r) add(++curR);
			ans[id]=ANS;
		}
		for(register int i=1;i<=m;++i) write(ans[i]),printf("\n");
		return 0;
}
