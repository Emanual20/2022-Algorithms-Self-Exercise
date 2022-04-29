/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;

typedef pair<ll, ll> pii;
const int inf = 0x3f3f3f3f;
struct edge{
    int to, w;
};
int n, m, k;
ll dist[maxn], vis[maxn];
vector<edge> edges[maxn];
void heap_dijkstra(int source){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    // min-heap
    priority_queue<pii, vector<pii>, greater<pii>> q;

    dist[source] = 0;
    q.push({0, source});

    while(!q.empty()){
        pii now = q.top();
        q.pop();
        if(vis[now.second])
            continue;
        vis[now.second] = 1;
        for (auto &iter : edges[now.second]){
            dist[iter.to] = min(dist[iter.to], dist[now.second] + iter.w);
            q.push({dist[iter.to], iter.to});
        }
    }
}

int a[maxn];
struct point{
    int x, y;
} p[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 2; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 1; i < n; i++){
        for (int j = 1; j <= n; j++){
            if(i != j){
                int cost = (abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y)) * k;
                edges[i].push_back({j, cost - a[i]});
            }
        }
    }

    heap_dijkstra(1);
    ll ans = dist[n];
    cout << ans << endl;
    return 0;
}