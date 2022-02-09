/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int dist[maxn], vis[maxn];
int n, m;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
void spfa(int source){
    queue<int> q;
    memset(dist, 0x3f, sizeof(dist));
    dist[source] = 0, q.push(source), vis[source] = 1;
    while(!q.empty()){
        int now = q.front();
        vis[now] = 0, q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(dist[to] > dist[now] + iter.w){
                dist[to] = dist[now] + iter.w;
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

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w});
    }

    spfa(1);

    if(dist[n] > inf / 2){
        cout << "impossible" << endl;
    }
    else
        cout << dist[n] << endl;
    return 0;
}