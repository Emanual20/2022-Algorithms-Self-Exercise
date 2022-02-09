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
const int maxn = 800 + 10;
const ll inf = 0x3f3f3f3f;
int dist[maxn], vis[maxn];
int k, n, m, tot[maxn];
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));

    dist[source] = 0, q.push(source), vis[source] = 1;
    
    while(!q.empty()){
        int now = q.front();
        vis[now] = 0, q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(dist[to] > dist[now] + iter.w){
                dist[to] = dist[now] + iter.w;
                // if 'to' is already in the queue q
                if(!vis[to]){
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n >> m;

    for (int i = 0; i < k; i++){
        int pos;
        cin >> pos;
        tot[pos]++;
    }

    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w});
        edges[to].push_back({fm, w});
    }

    ll ans = inf * inf;
    for (int i = 1; i <= n; i++){
        spfa(i);
        ll tmp = 0;
        for (int j = 1; j <= n; j++){
            tmp += dist[j] * 1ll * tot[j];
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}