# 缩点，强连通
```cpp
int In[Maxn],Out[maxn],Belong[maxn],dfn[maxn],low[maxn],stack[maxn],time=0,Bcnt=0,top=0,tail=0;
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
    for(int i=1;i<=n;++i)
	{
		for(int j=fit[i];j!=-1;j=a[j].nxt)
		{
			u=a[j].to;
			if(Belong[i]!=Belong[u]) Out[Belong[i]]++,In[Belong[u]]++;
		}
	}
}
```