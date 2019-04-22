#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 1000002
#define lson i<<1
#define rson i<<1|1
using namespace std;
inline void swap(int &a,int &b){a^=b^=a^=b;}
class min_heap
{
	public:
		int size;
		int h[maxn];
	public:
		inline void siftdown(int);
		inline void siftup(int);
		inline int top();
		inline void dellmin();
		inline void push(int);
}q;
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
inline void min_heap::siftdown(int i)
{
	int flag=0,t;
	while(lson<=size&&flag==0)
	{
		t=h[lson]<h[i]?lson:i;
		if(rson<=size)t=h[rson]<h[t]?rson:t;
		if(t!=i) swap(h[i],h[t]),i=t;else flag=1;
	}
	return;
}
inline void min_heap::siftup(int i)
{
	int flag=0;
	while(i!=1&&flag==0)
	{
		if(h[i>>1]>h[i]) swap(h[i>>1],h[i]);else flag=1;
		i>>=1;
	}
	return;
}
inline int min_heap::top(){return h[1];}
inline void min_heap::dellmin(){h[1]=h[size--];siftdown(1);}
inline void min_heap::push(int x){h[++size]=x;siftup(size);}
int main()
{
	int n,t1,t2;
	read(n);
	q.size=0;
	for(register int i=1;i<=n;++i)
	{
		read(t1);
		if(t1==1) read(t2),q.push(t2);
		if(t1==2) printf("%d\n",q.top());
		if(t1==3) q.dellmin();
	}
	return 0;
}
