#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
/**2台机器,n件任务,必须先在S1上做,再在S2上做.
任务之间先做后做任意.求最早的完工时间.
这是一个经典问题: 2台机器的情况下有多项式算法(Johnson算法),3台或以上的机器是NP-hard算法。

Johnson算法:
(1)把作业按工序加工时间分成两个子集,第一个集合中在S1上做的时间比在S2上少,其它的作业放到第二个集合;
　 先完成第一个集合里面的作业,再完成第二个集合里的作业.
(2)对于第一个集合,其中的作业顺序是按在S1上的时间的不减排列;
　 对于第二个集合, 其中的作业顺序是按在S2上的时间的不增排列.**/
struct task
{
    int a;
    int b;
} TaskA[MAXN], TaskB[MAXN];

bool cmpA(task a, task b)
{
    return a.a <= b.a;
}

bool cmpB(task a, task b)
{
    return a.b >= b.b;
}

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;

    int a, b;
    int posA = 0, posB = 0;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        if (a < b)
        {
            TaskA[posA].a = a;
            TaskA[posA++].b = b;
            sumA += b;
        }
        else
        {
            TaskB[posB].a = a;
            TaskB[posB++].b = b;
            sumB += a;
        }
    }
    sort(TaskA, TaskA + posA, cmpA);
    sort(TaskB, TaskB + posB, cmpB);

    for (int i = 0; i < posB; i++)
    {
        TaskA[posA++] = TaskB[i];
    }

    int ans = TaskA[0].a + TaskA[0].b;
    int sum = TaskA[0].a;
    for (int i = 1; i < posA; i++)
    {
        sum += TaskA[i].a;
        ans = sum < ans ? ans + TaskA[i].b : sum + TaskA[i].b;
    }

    cout << ans << '\n';

    return 0;
}