#include<bits/stdc++.h>
#define Maxn 20010
#define Maxm 100004
using namespace std;
int Stack[Maxn],top=0,dfn[Maxn],low[Maxn],In[Maxn],Out[Maxn],Belong[Maxn],num=0;
int gedian=0;
bitset<Maxn> Cut;
int Bcnt=0;
struct Edge{
    int v;
    int next;
}edges[Maxm*2];
int tot=0,First[Maxn];
inline void addEdge(int x,int y)
{
    edges[++tot].next=First[x];
    edges[tot].v=y;
    First[x]=tot; 
}
void tarjan(int u,int root)
{
    int child=0;
    dfn[u]=low[u]=++num;
    for(int i=First[u];i;i=edges[i].next)
    {
        int v=edges[i].v;
        if(!dfn[v]){
            tarjan(v,root);
            low[u]=min(low[v],low[u]);
            if(u==root) ++child;
            else if(low[v]>=dfn[u]) Cut[u]=1;
        }else
        {
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(child>=2&&u==root) Cut[u]=1;
}
int n,m;
int main()
{
    memset(dfn,0,sizeof(dfn));
    memset(First,0,sizeof(First));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        addEdge(x,y);
        addEdge(y,x);
    }
    for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i,i);
    for(int i=1;i<=n;++i) if(Cut[i]) ++gedian;
    cout<<gedian<<endl;
    for(int i=1;i<=n;++i) if(Cut[i]) printf("%d ",i);
    return 0;
}