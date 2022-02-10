/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 25000 + 10;
const int inf = 0x3f3f3f3f;
int dist[maxn], vis[maxn], cnt[maxn], HasNegaRing;
int n, r, p, s;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));

    dist[source] = 0, q.push(source), vis[source] = 1;
    
    while(!q.empty()){
        int now = q.front();
        vis[now] = 0, q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(dist[to] > dist[now] + iter.w){
                dist[to] = dist[now] + iter.w;

                // if exist negative ring
                cnt[to] = cnt[now] + 1;
                if (cnt[to] > n)
                {
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

    cin >> n >> r >> p >> s;
    for (int i = 0; i < r; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w});
        edges[to].push_back({fm, w});
    }

    for (int i = 0; i < p; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w});
    }

    spfa(s);

    for (int i = 1; i <= n; i++){
        if(dist[i] > inf / 2){
            cout << "NO PATH" << endl;
        }
        else
            cout << dist[i] << endl;
    }
}