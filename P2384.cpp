#if 0

#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#define mod 9987
using namespace std;
struct edge {
    int to, next, w;
}e[1000005];
queue<int> q;
int first[1005], po[1005][2], vis[1005], tot = 0;
double dis[1005];
void addedge(int u, int v, int val)
{
    e[++tot].w = val;
    e[tot].to = v;
    e[tot].next = first[u];
    first[u] = tot;
}
int main()
{
    int n, m, x, y, z;
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        addedge(x, y, z);
    }
    memset(dis, 127, sizeof(dis));
    dis[1] = 0; vis[1] = 1;
    q.push(1);
    while (q.size())
    {
        int now = q.front(); q.pop();
        vis[now] = 0;
        for (int i = first[now]; i; i = e[i].next)
        {
            int v = e[i].to;
            if (dis[v] > dis[now] + log(e[i].w))
            {
                dis[v] = dis[now] + log(e[i].w);
                po[v][0] = now; po[v][1] = e[i].w;
                if (!vis[v]) { vis[v] = 1; q.push(v); }
            }
        }
    }
    int ans = 1, pos = n;
    while (pos != 1)
    {
        ans *= po[pos][1];
        ans %= mod;
        pos = po[pos][0];
    }
    printf("%d\n", ans);
    return 0;
}
#endif // 1
