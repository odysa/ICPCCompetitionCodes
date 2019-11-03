#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 110;

int sgn(double x)
{
    if (fabs(x) < eps)
    {
        return 0;
    }
    if (x < 0)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

double b[MAXN][MAXN];
double det(double a[][MAXN], int n)
{
    int i, j, k, sign = 0;
    double ret = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (sgn(b[i][i]) == 0)
        {
            for (j = i + 1; j < n; j++)
            {
                if (sgn(b[j][i]) != 0)
                {
                    break;
                }
            }
            if (j == n)
            {
                return 0;
            }
            for (k = i; k < n; k++)
            {
                swap(b[i][k], b[j][k]);
            }
            sign++;
        }
        ret *= b[i][i];
        for (k = i + 1; k < n; k++)
        {
            b[i][k] /= b[i][i];
        }
        for (j = i+1; j < n; j++)
        {
            for (k = i+1; k < n; k++)
            {
                b[j][k] -= b[j][i] * b[i][k];
            }
        }
    }
    if (sign & 1)
    {
        ret = -ret;
    }
    return ret;
}

double a[MAXN][MAXN];
int g[MAXN][MAXN];

int main()
{
    int T;
    int n, m;
    int u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        while (m--)
        {
            scanf("%d%d", &u, &v);
            u--;
            v--;
            g[u][v] = g[v][u] = 1;
        }
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && g[i][j])
                {
                    a[i][i]++;
                    a[i][j] = -1;
                }
            }
        }
        double ans = det(a, n - 1);
        printf("%.0lf\n", ans);
    }
    return 0;
}