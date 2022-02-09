/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e3 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int fm, to;
    double w;
};
int src, dst, vis[maxn];
int n, m;
double dist[maxn], edges[maxn][maxn];
void naive_dijkstra(int source){
    memset(vis, 0, sizeof(vis));
    dist[source] = 1;
    cout << n << " " << source << endl;
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
                dist[j] = min(dist[j], dist[now_index] * edges[now_index][j]);
            }
        }
        for (int _ = 1; _ <= 3; _++)
            cout << dist[_];
        cout << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm][to] = edges[to][fm] = 1 - w * 1.0 / 100;
    }
    for (int i = 1; i <= n; i++){
        edges[i][i] = 1;
    }

    cin >> src >> dst;
    naive_dijkstra(src);
    cout << fixed << setprecision(8) << ((long double)1.0 / dist[dst]) << endl;
    return 0;
}