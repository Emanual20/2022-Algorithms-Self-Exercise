/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2 + 10;
const int inf = 0x3f3f3f3f;
int n, m, edges[maxn][maxn], dist[maxn], vis[maxn];
void naive_dijkstra(int source){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[source] = 0;
    for (int i = 1; i <= n; i++){
        int now_min = inf, now_index = -1;
        for (int j = 1; j <= n; j++){
            if(now_min > dist[j] && !vis[j]){
                now_min = dist[j];
                now_index = j;
            }
        }
        vis[now_index] = 1, dist[now_index] = now_min;
        for (int j = 1; j <= n; j++){
            if(!vis[j]){
                dist[j] = min(dist[j], dist[now_index] + edges[now_index][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(edges, 0x3f, sizeof(edges));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm][to] = min(edges[fm][to], w);
    }

    naive_dijkstra(1);
    cout << (dist[n] == inf ? -1 : dist[n]) << endl;
    return 0;
}