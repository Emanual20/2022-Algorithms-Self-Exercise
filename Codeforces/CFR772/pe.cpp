/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct item{
    int type, fm, to;
};
vector<item> items;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n, m;
int color[maxn], pos[maxn], vis[maxn];
bool CheckPartBipartite(int root){
    int tot = 0;
    color[root] = 1;

    queue<int> q;
    q.push(root), vis[root] = 1, tot = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            int to = iter.to;
            if(!vis[to]){
                vis[to] = 1, tot++, color[to] = 3 - color[now], q.push(to);
            }
            else if(color[to] == color[now]){
                return false;
            }
        }
    }
    return true;
}

bool CheckBipartite(){
    int ret = 1;
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            ret = ret && CheckPartBipartite(i);
        }
    }
    return ret;
}

int d[maxn], res = 0, tot = 0;

bool Topology_Sort(int source){
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto &iter : edges[now]){
            pos[iter.to] = max(pos[now] + iter.w, res + 1);
            res++;
            d[iter.to]--;
            if(d[iter.to] == 0){
                q.push(iter.to), tot++;
            }
        }
    }
    return tot == n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int type, fm, to;
        cin >> type >> fm >> to;
        items.push_back({type, fm, to});
        edges[fm].push_back({to, 1}), edges[to].push_back({fm, 1});
    }

    int Is_Bipartite = CheckBipartite();
    if(!Is_Bipartite){
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++){
        edges[i].clear();
    }

    for (int i = 0; i < items.size(); i++){
        int ntype = items[i].type, nfm = items[i].fm, nto = items[i].to;
        if(ntype == 1){
            if(color[nfm] == 1){
                edges[nfm].push_back({nto, 1});
            }
            else{
                edges[nto].push_back({nfm, 1});
            }
        }
        else{
            if(color[nfm] == 1){
                edges[nto].push_back({nfm, 1});
            }
            else{
                edges[nfm].push_back({nto, 1});
            }
        }
    }

    for (int i = 1; i <= n; i++){
        edges[0].push_back({i, 1});
    }
    for (int i = 0; i <= n; i++){
        for(auto &iter : edges[i]){
            d[iter.to]++;
        }
    }
    int is_topo = Topology_Sort(0);
    if(!is_topo){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++){
        cout << (color[i] == 1 ? "L" : "R") << " " << pos[i] << endl;
    }
    return 0;
}