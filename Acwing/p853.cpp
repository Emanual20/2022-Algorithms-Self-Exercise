/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2 + 10;
const int inf = 0x3f3f3f3f;
const int ansinf = 5e6;
int dist[maxn], distg[maxn];
int n, k, m;
struct edge{
    int fm, to, w;
};
vector<edge> edges;
void bellman_ford(int source){
    dist[source] = 0;
    for (int i = 0; i < k; i++){
        memcpy(distg, dist, sizeof(distg));
        for (auto &now : edges){
            distg[now.to] = min(distg[now.to], dist[now.fm] + now.w);
        }
        memcpy(dist, distg, sizeof(distg));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges.push_back({fm, to, w});
    }

    bellman_ford(1);

    if(dist[n]>ansinf)
        cout << "impossible" << endl;
    else
        cout << dist[n] << endl;
}