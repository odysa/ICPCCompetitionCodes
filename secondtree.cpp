#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
int lowc[MAXN];
int pre[MAXN];
int MAX[MAXN][MAXN];
bool used[MAXN][MAXN];

int Prim(int cost[][MAXN], int n)
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    memset(MAX, 0, sizeof(MAX));
    memset(used, false, sizeof(used));
    vis[0] = true;
    pre[0] = -1;
    lowc[0] = 0;

    for (int i = 1; i < n; i++)
    {
        lowc[i] = cost[0][i];
        pre[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        }
        if (minc == INF)
        {
            return -1;
        }
        ans += minc;
        vis[p] = true;
        used[p][pre[p]] = used[pre[p]][p] = true;
        for (int j = 0; j < n; j++)
        {
            if (vis[j])
            {
                MAX[j][p] = MAX[p][j] = max(MAX[j][pre[p]], lowc[p]);
            }
            if (!vis[j] && lowc[j] > cost[p][j])
            {
                lowc[j] = cost[p][j];
                pre[j] = p;
            }
        }
    }

    return ans;
}