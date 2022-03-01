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
const int maxn = 1e5 + 10;
const int maxdim2 = 50 + 10;
const int inf = 0x3f3f3f3f;
struct edge{
    int to, w;
};
int n, m, t, k;
int dist[maxn], vis[maxn];
ll MOD, dp[maxn][maxdim2];
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
        else{
            seq.push_back(now.second);
        }
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

    cin>>t;
    while(t--){
        cin >> n >> m >> k >> MOD;
        for (int i = 1; i <= m; i++){
            int fm, to, w;
            cin >> fm >> to >> w;
            edges[fm].push_back({to, w});
        }
        heap_dijkstra(1), dp[1][0] = 1;
        for (int _ = 0; _ <= k; _++){
            for (int i = 0; i < seq.size(); i++){
                int now = seq[i];
                for(auto &iter : edges[now]){
                    int nto = iter.to, nw = iter.w;
                    for (int j = 0; j + _ <= k; j++){
                        if(dist[now] + nw == dist[nto] + j){
                            dp[nto][_ + j] += dp[now][_];
                            dp[nto][_ + j] %= MOD;
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i <= k; i++){
            ans = (ans + dp[n][i]) % MOD;
        }
        cout << ans << endl;

        memset(dp, 0, sizeof(dp));
        seq.clear();
        for (int i = 1; i <= n; i++){
            edges[i].clear();
        }
    }
    return 0;
}