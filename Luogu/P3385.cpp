/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
const int inf = 0x3f3f3f3f;
int dist[maxn], vis[maxn], cnt[maxn], HasNegaRing;
int n, m, t;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    HasNegaRing = 0;

    if(source == -1){
        for (int i = 1; i <= n; i++){
            q.push(i), vis[i] = 1;
        }
    }
    else{
        memset(dist, 0x3f, sizeof(dist));
        dist[source] = 0, q.push(source), vis[source] = 1;
    }
    
    while(!q.empty()){
        int now = q.front();
        vis[now] = 0, q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(dist[to] > dist[now] + iter.w){
                dist[to] = dist[now] + iter.w;

                // if exist negative ring
                cnt[to] = cnt[now] + 1;
                if (cnt[to] >= n){
                    HasNegaRing = 1;
                    return;
                }
                
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
    cin >> t;
    while(t--){
        for (int i = 0; i < maxn; i++){
            edges[i].clear();
        }

        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int fm, to, w;
            cin >> fm >> to >> w;
            if(w>=0){
                edges[fm].push_back({to, w});
                edges[to].push_back({fm, w});
            }
            else{
                edges[fm].push_back({to, w});
            }
        }

        spfa(1);
        cout << (HasNegaRing ? "YES" : "NO") << endl;
    }
    return 0;
}