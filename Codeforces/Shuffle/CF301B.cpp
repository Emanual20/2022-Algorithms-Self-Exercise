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
ll dist[maxn], vis[maxn], cnt[maxn], HasNegaRing;
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    HasNegaRing = 0;

    if(source == -1){
        for (int i = 1; i <= n; i++){
            q.push(i), vis[i] = 1;
        }
    }
    else{
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

    spfa(1);
    ll ans = dist[n];
    cout << ans << endl;
    return 0;
}