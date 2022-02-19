/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;
int dist[maxn], vis[maxn], cnt[maxn], HasNegaRing;
int n, m;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(dist, -0x3f, sizeof(dist));
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
            if(dist[to] < dist[now] + iter.w){
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b + 1, c});
    }

    for (int i = 1; i <= 50001; i++){
        edges[i - 1].push_back({i, 0});
    }
    for (int i = 1; i <= 50001; i++){
        edges[i].push_back({i - 1, -1});
    }

    n = 50001;
    spfa(0);
    cout << dist[50001] << endl;
    return 0;
}