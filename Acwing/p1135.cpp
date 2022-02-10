/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 5e4 + 10;
const ll inf = 0x3f3f3f3f;
struct edge{
    int fm, to, w;
};
int n, m, dist[maxn], vis[maxn];
vector<edge> edges[maxn];
vector<int> dests;
map<int, vector<int>> calculated_dists;
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
vector<int> seq;
ll ans = inf * inf;
int vis_dfs[6];
void dfs(int step){
    if(step == 5){
        ll tmp = 0;
        seq.push_back(1);
        for (int i = seq.size() - 1; i >= 1; i--){
            tmp += calculated_dists[seq[i]][seq[i - 1]];
        }
        seq.pop_back();
        ans = min(ans, tmp);
        return;
    }
    for (int i = 0; i < dests.size(); i++){
        if(!vis_dfs[i]){
            vis_dfs[i] = 1;
            seq.push_back(dests[i]);
            dfs(step + 1);
            seq.pop_back();
            vis_dfs[i] = 0;
        }
    }
}
void prepare_calculated_dists(){
    heap_dijkstra(1);
    vector<int> tmp = {0};
    for (int j = 1; j <= n; j++){
        tmp.push_back(dist[j]);
    }
    calculated_dists[1] = tmp;
    for(auto &dest : dests){
        heap_dijkstra(dest);
        vector<int> tmp = {0};
        for (int j = 1; j <= n; j++){
            tmp.push_back(dist[j]);
        }
        calculated_dists[dest] = tmp;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < 5; i++){
        int x;
        cin >> x;
        dests.push_back(x);
    }

    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({fm, to, w});
        edges[to].push_back({to, fm, w});
    }

    prepare_calculated_dists();

    seq.clear();
    memset(vis_dfs, 0, sizeof(vis_dfs));
    dfs(0);

    cout << ans << endl;
    return 0;
}