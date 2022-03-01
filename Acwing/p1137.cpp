/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 150000 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int to, w;
};
int n, m, src, dist[maxn], vis[maxn];
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>m>>src){
        for (int i = 1; i <= m; i++){
            int fm, to, w;
            cin >> fm >> to >> w;
            edges[to].push_back({fm, w});
        }
        int dest_num;
        cin >> dest_num;
        heap_dijkstra(src);
        int ans = inf;
        for (int i = 1; i <= dest_num; i++){
            int x;
            cin >> x;
            ans = min(ans, dist[x]);
        }
        cout << (ans >= inf / 2 ? -1 : ans) << '\n';
        for (int i = 1; i <= n; i++){
            edges[i].clear();
        }
    }
}