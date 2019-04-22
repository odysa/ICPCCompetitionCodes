#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define maxn 12345
#define lson i<<1
#define rson i<<1|1
#define root i
#define father i>>1
using namespace std;
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
class heap
{
	public:
		int size;
		int h[maxn];
	public:
		inline void push(int);
		inline void dellmax();
		inline int top();
		inline void siftdown(int);
		inline void siftup(int);
		inline void setup_heap();
};
inline void swap(int &a,int &b){a^=b^=a^=b;}
inline int heap::top(){return h[1];}
inline void heap::siftdown(int i)
{
	int flag=0,t;
	while(lson<=size&&flag==0)
	{
		t=h[root]<h[lson]?lson:root;
		if(rson<=size)t=h[t]<h[rson]?rson:t;
		if(t!=i) swap(h[t],h[i]),i=t;
		else flag=1;	 
	}
	return;
}
inline void heap::siftup(int i)
{
	int flag=0;
	if(i==1) return;
	while(father!=1&&flag==0)
	{
		if(h[i]>h[father]) swap(h[i],h[father]);
		else flag=1;
		i=father;
	}
	return;
}
inline void heap::setup_heap() {for(int i=size/2;i>=1;--i) siftdown(i);}
inline void heap::push(int x)
{
	++size;
	h[size]=x;
	siftup(size);
	return;
}
inline void heap::dellmax()
{
	h[1]=h[size];
	--size;
	siftdown(1);
	return;
}
heap q;
int main()
{
	read(q.size);
	for(int i=1;i<=q.size;++i) read(q.h[i]);
	q.setup_heap();
	int n=q.size;
	for(int i=1;i<=n;++i) write(q.top()),putchar(' '),q.dellmax();
	return 0;
}

