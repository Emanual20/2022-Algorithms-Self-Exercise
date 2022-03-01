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
typedef pair<int, int> pii;
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int to, w;
};
int t, n, m, dist[maxn], vis[maxn], src, dst, dp[maxn][2];
vector<edge> edges[maxn];
vector<int> seq;
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
        if(vis[now.second]){
            continue;
        }
        else
            seq.push_back(now.second);
        vis[now.second] = 1;
        for (auto &iter : edges[now.second]){
            int nto = iter.to, nw = iter.w;
            dist[nto] = min(dist[nto], dist[now.second] + nw);
            q.push({dist[nto], nto});
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        seq.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int fm, to, w;
            cin >> fm >> to >> w;
            edges[fm].push_back({to, w});
        }
        cin >> src >> dst;
        heap_dijkstra(src);
        dp[src][0] = 1;
        for (int k = 0; k < 2; k++){
            for (int i = 0; i < seq.size(); i++){
                int now = seq[i];
                for (auto &iter : edges[now]){
                    int nto = iter.to, nw = iter.w;
                    if (dist[now] + nw == dist[nto]){
                        dp[nto][k] += dp[now][k];
                    }
                    else if(k == 0 && dist[now] + nw == dist[nto] + 1){
                        dp[nto][k + 1] += dp[now][k];
                    }
                }
            }
        }
        cout << dp[dst][0] + dp[dst][1] << endl;
        for (int i = 1; i <= n; i++){
            edges[i].clear();
        }
    }
    return 0;
}