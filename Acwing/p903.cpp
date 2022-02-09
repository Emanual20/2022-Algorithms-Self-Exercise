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
int m, n, node_tot = 0;
struct item{
    int p, l, x;
    vector<pii> Alternatives;
};
vector<item> items;
vector<int> accepts;

int edges[maxn][maxn], dist[maxn], vis[maxn], valid[maxn];
void naive_dijkstra(int source, int left, int right){
    memset(valid, 0, sizeof(valid));
    for (int i = 1; i < node_tot; i++){
        valid[i] = (left <= items[i].l && items[i].l <= right);
    }
    valid[node_tot] = 1;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[source] = 0;
    for (int i = 1; i <= node_tot; i++){
        int now_min = inf, now_index = -1;
        for (int j = 1; j <= node_tot; j++){
            if(now_min > dist[j] && !vis[j] && valid[j]){
                now_min = dist[j];
                now_index = j;
            }
        }
        if(now_index == -1) break;
        vis[now_index] = 1, dist[now_index] = now_min;
        for (int j = 1; j <= node_tot; j++){
            if(!vis[j] && valid[j]){
                dist[j] = min(dist[j], dist[now_index] + edges[now_index][j]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    items.push_back({-1, -1, -1, vector<pii>()});
    for (int i = 1; i <= n; i++){
        int p, l, x;
        cin >> p >> l >> x;
        vector<pii> tmp;
        for (int j = 1; j <= x; j++){
            int t, v;
            cin >> t >> v;
            tmp.push_back({t, v});
        }
        items.push_back({p, l, x, tmp});
    }

    memset(edges, 0x3f, sizeof(edges));
    for (int i = 1; i < items.size(); i++){
        for (int j = 0; j < items[i].x; j++){
            int to = items[i].Alternatives[j].first;
            edges[i][to] = items[i].Alternatives[j].second;
        }
    }

    // add a super destination
    node_tot = n + 1;
    for (int i = 1; i < items.size(); i++){
        edges[i][n + 1] = items[i].p;
    }

    int ans = inf;
    for (int left = items[1].l - m; left <= items[1].l; left++){
        naive_dijkstra(1, left, left + m);
        ans = min(ans, dist[n + 1]);
    }
    cout << ans << endl;
    return 0;
}