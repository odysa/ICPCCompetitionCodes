#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 100002
using namespace std;
int sz,fa[maxn],child[maxn][2],key[maxn],size[maxn],cnt[maxn],root;
inline void read(int &data)
{
	char ch=getchar();
	data=0;
	int flag=0;
	if(ch=='-')  flag=1;
	while(ch<'0'||ch>'9') ch=getchar();
	do{
		data=data*10+ch-48;
		ch=getchar();
	}while(ch>='0'&&ch<='9');
	if(flag==1) data=-data;
	return ;
}
void write(int data)
{
	if(data<0) data=-data,putchar('-');
	if(data>9) write(data/10);
	putchar((data%10)+48);
	return;
}
inline void clear(int x)
{
	fa[x]=child[x][0]=child[x][1]=cnt[x]=key[x]=size[x]=0;
	return;
}
inline int get(int x)
{
	return child[fa[x]][1]==x;
}
inline void update(int x)
{
	if(x)
	{
		size[x]=cnt[x];
		if(child[x][0]) size[x]+=size[child[x][0]];
		if(child[x][1]) size[x]+=size[child[x][1]];
	}
	return;
}
inline void rotate(int x)
{
	int old=fa[x],oldf=fa[old],which=get(x);
	child[old][which]=child[x][which^1];
	fa[child[old][which]]=old;
	fa[old]=x;
	child[x][which^1]=old;             
	fa[x]=oldf;
	if(oldf) child[oldf][child[oldf][1]==old]=x;
	update(old);
	update(x);
}
inline void splay(int x)
{
	for(int y;y=fa[x];rotate(x))
	 if(fa[y]) rotate(get(y)==get(x)?y:x);
	root=x; 
}
inline void insert(int v)
{
	if(root==0) {sz++;child[sz][0]=child[sz][1]=fa[sz]=0;key[sz]=v;cnt[sz]=1;size[sz]=1;root=sz;return;}
	int now=root,y=0;
	while(1)
	{
		if(key[now]==v) {++cnt[now];update(now);update(y);splay(now);break;}
		y=now;
		now=child[now][key[now]<v];
		if(now==0)
		{
			++sz;
			child[sz][1]=child[sz][0]=0;
			++cnt[sz];
			size[sz]=1;
			key[sz]=v;
			fa[sz]=y;
			child[y][key[y]<v]=sz;
			update(sz);
			splay(sz);
			break;
		}
	}  
}
inline int find(int v)
{
	int now=root,ans=0;
	while(1)
	{
		if(key[now]>v) now=child[now][0];
		else
		{
			ans+=child[now][0]?size[child[now][0]]:0;
			if(v==key[now]) {splay(now);return ans+1;}
			ans+=cnt[now];
			now=child[now][1];
		}
	}
}
inline int search(int v)
{
	int now=root;
	while(1)
	{
		if(key[now]==v) return now;
		now=child[now][v>key[now]];
	}
}
inline int findx(int x)
{
	int now=root;
	while(1)
	{ 
		if(child[now][0]&&x<=size[child[now][0]]) now=child[now][0];
		else
		{ 
			int tmp=(child[now][0]?size[child[now][0]]:0)+cnt[now];
			if(x<=tmp) return key[now];
			x-=tmp;
			now=child[now][1];
		}
	}
}
inline int pre()
{
	int now=child[root][0];
	while(child[now][1]) now=child[now][1];
	return now;
}
inline int nxt()
{
	int now=child[root][1];
	while(child[now][0]) now=child[now][0];
	return now;
}
inline void dell(int x)
{
	int whatever=find(x);
	if(cnt[root]>1) {--cnt[root];return;}
	if(!child[root][1]&&!child[root][0]) {clear(root);root=0;return;}
	if(!child[root][0]) {int oldroot=root;root=child[root][1];fa[root]=0;clear(oldroot);return;}
	else if(!child[root][1]) {int oldroot=root;root=child[root][0];fa[root]=0;clear(oldroot);return;}
	int leftbig=pre(),oldroot=root;
	splay(leftbig);
	fa[child[oldroot][1]]=root;
	child[root][1]=child[oldroot][1];
	clear(oldroot);
	update(root);
	return;
}
int main()
{
	int n,k,t;
	read(n);
	for(register int i=1;i<=n;++i)
	{
		read(k);read(t);
		if(k==1) insert(t);
		if(k==2) dell(t);
		if(k==3) write(find(t)),printf("\n");
		if(k==4) write(findx(t)),printf("\n");
		if(k==5) insert(t),write(key[pre()]),printf("\n"),dell(t);
		if(k==6) insert(t),write(key[nxt()]),printf("\n"),dell(t);
	}
	return 0;
	
}
