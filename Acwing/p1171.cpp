/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
int n, q;

/*
* dsu part
*/
int f[maxn], sz[maxn];
// remember to call dsu_init
void dsu_init(){
    for (int i = 1; i <= n; i++)
        f[i] = i, sz[i] = 1;
}
int find(int k){
    if(f[k] == k)
        return k;
    return f[k] = find(f[k]);
}
void merge(int dst, int src){
    int ds = find(dst), sr = find(src);
    f[sr] = ds, sz[ds] += sz[sr];
}

struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int dist[maxn];

const int maxq = 2e4 + 10;
struct query{
    int x, y, index;
};
int ans[maxq];
vector<query> queries[maxn];

void dfs(int now, int fm){
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            dist[nto] = dist[now] + nw;
            dfs(nto, now);
        }
    }
}

int st[maxn];
void tarjan(int now){
    st[now] = 1;
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(!st[nto]){
            tarjan(nto);
            merge(now, nto);
        }
    }
    
    for(auto &iter : queries[now]){
        int ancestor = -1;
        if(st[iter.y] == 1){
            ancestor = iter.y;
            ans[iter.index] = dist[iter.x] + dist[iter.y] - 2 * dist[ancestor];
        }
        else if(st[iter.y] == 2){
            ancestor = find(iter.y);
            ans[iter.index] = dist[iter.x] + dist[iter.y] - 2 * dist[ancestor];
        }
    }
    st[now] = 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i < n; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w}), edges[to].push_back({fm, w});
    }

    for (int i = 1; i <= q; i++){
        int x, y;
        cin >> x >> y;
        queries[x].push_back({x, y, i}), queries[y].push_back({y, x, i});
    }

    dsu_init();
    dfs(1, -1);
    tarjan(1);

    for (int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
    return 0;
}