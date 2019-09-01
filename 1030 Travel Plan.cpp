#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9 + 10;
const int maxv = 510;
int G[maxv][maxv], d[maxv], c[maxv], cost[maxv][maxv];
bool vis[maxv];
int n, m, s, dd;
int pre[maxv];
vector<int>path;
void Dijkstra(int s)
{
    fill(d, d + maxv, INF);
    d[s] = 0;
    fill(c, c + maxv, INF);
    c[s] = 0;
    while (1)
    {
        int u = -1, MIN = INF;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i]&&d[i] < MIN)MIN = d[i], u = i;
        }
        if (u == -1)return;
        vis[u] = true;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && G[u][i])
            {
                if (d[u] + G[u][i] < d[i])
                {
                    d[i] = d[u] + G[u][i];
                    pre[i] = u;
                    c[i] = c[u] + cost[u][i];
                }
                else if (d[u] + G[u][i] == d[i] && c[u] + cost[u][i] < c[i])
                {
                    pre[i] = u;
                    c[i] = c[u] + cost[u][i];
                }
            }
        }
    }
}
void DFS(int v)
{
    if (v == s)
    {
        path.push_back(v);
        return;
    }
    DFS(pre[v]);
    path.push_back(v);
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &dd);
    for (int i = 0; i < m; i++)
    {
        int c1, c2, dis, cc;
        scanf("%d%d%d%d", &c1, &c2, &dis, &cc);
        G[c1][c2] = G[c2][c1] = dis;
        cost[c1][c2] = cost[c2][c1] = cc;
    }
    Dijkstra(s);
    DFS(dd);
    for (int i = 0; i < path.size(); i++)
    {
        printf("%d ", path[i]);
    }
    printf("%d %d", d[dd], c[dd]);
    return 0;
}
