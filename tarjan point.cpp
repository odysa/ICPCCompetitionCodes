#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define maxn 2003
using namespace std;
struct edge
{
	int to,nxt;
}a[maxn];
int fit[maxn],tot=0;
int n,m;
inline void add(int x,int y)
{
	a[tot].to=y;
	a[tot].nxt=fit[x];
	fit[x]=tot++;
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
	return ;
}
void write(int data)
{
	if(data>9) write(data/10);
	putchar((data%10)+48);
	return;
}
int out[maxn],Belong[maxn],dfn[maxn],low[maxn],stack[maxn],time=0,Bcnt=0,top=0,tail=0;
int instack[maxn];
inline int min(int x,int y)
{
	return x>y?y:x;
}
void tarjan(int k)
{
	dfn[k]=low[k]=++time;
	stack[++tail]=k;
	instack[k]=1;
	int tmp;
	for(int i=fit[k];i!=-1;i=a[i].nxt)
	{
		tmp=a[i].to;
		if(!dfn[tmp]) tarjan(tmp),low[k]=min(low[k],low[tmp]);
		else if(instack[tmp]) low[k]=min(low[k],low[tmp]);
	}
	if(dfn[k]==low[k])
	{
		Bcnt++;
		do{
			tmp=stack[tail--];
			Belong[tmp]=Bcnt;
			instack[tmp]=0;
		}while(tmp!=k);
	}
	return;
}

int main()
{
	read(n);read(m);
	int u,v;
	int x,y;
	memset(fit,-1,sizeof(fit));
	for(int i=1;i<=m;++i)
	{
		read(x);read(y);       
		add(x,y);
	}
	for(int i=1;i<=n;++i)
	 if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;++i)
	{
		for(int j=fit[i];j!=-1;j=a[j].nxt)
		{
			u=a[j].to;
			if(Belong[i]!=Belong[u]) out[Belong[i]]++;
		}
	}
	int num=0,ans=0,flag;
	for(int i=1;i<=Bcnt;++i)
	{
		if(out[i]==0) num++,flag=i;
	}
	if(num==1)
	{
		for(int i=1;i<=n;++i)
		 if(Belong[i]==flag) ++ans;
		write(ans);
	}
	else
		printf("0\n");
	return 0;
}
