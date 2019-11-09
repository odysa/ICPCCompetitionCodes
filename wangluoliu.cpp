#include<bits/stdc++.h>
#define maxn 10000 +5
#define maxm 100010
#define inf 1e9
using namespace std;
int head[maxn];
struct Edge{
    int v;
    int val;
    int next;
}edge[maxm*2];
int deep[maxn],n,m,s,t,tot=0;
inline void add(int u,int v,int w,int flag)
{
    edge[tot].next=head[u];
    edge[tot].v=v;
    if(flag) edge[tot].val=w;
    head[u]=tot++;
}
int BFS(int s,int t)
{
    memset(deep,0x7f,sizeof(deep));
    queue<int> q;
    deep[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].v;
            if(edge[i].val&&deep[v]>inf)
            {
                deep[v]=deep[u]+1;
                q.push(v);
            }
        }
    }
    if(deep[t]<inf) return 1;
    return 0;
}
int DFS(int u,int t,int lim)
{
    int flow=0,f;
    if(u==t||!lim) return lim;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].v;
        if(deep[u]+1==deep[v]&&(f=DFS(v,t,min(lim,edge[i].val))))
        {
            flow+=f;
            edge[i].val-=f;
            edge[i^1].val+=f;
            lim-=f;
            if(!lim) break;
        }
    }
    return flow;
}
int Dinic(int s,int t)
{
    int maxflow=0;
    while(BFS(s,t)) maxflow+=DFS(s,t,inf); 
    return maxflow;
}
int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z,1);
        add(y,x,z,0);
    }
    cout<<Dinic(s,t);
    return 0;
}