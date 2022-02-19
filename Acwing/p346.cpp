/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6e3 + 10;
const int inf = 0x3f3f3f3f;
int t, n, m, f[maxn], sz[maxn];
struct edge{
    int fm, to, w;
};
vector<edge> edges;
bool comp(edge e1, edge e2){
    if(e1.w == e2.w) return e1.fm < e2.fm;
    return e1.w < e2.w;
}
void init_dsu(int x){
    for(int i = 1; i <= x; i++){
        f[i] = i, sz[i] = 1;
    }
}
int find(int x){
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
void merge(int src, int dst){
    int s = find(src), d = find(dst);
    f[s] = d, sz[d] += sz[s];
}

int kruskal(){
    init_dsu(n);
    int ret = 0, tot = 0;
    sort(edges.begin(), edges.end(), comp);
    for(auto &now : edges){
        if(tot == n - 1 || find(now.fm) == find(now.to)){
            continue;
        }
        ret += (sz[find(now.fm)] * sz[find(now.to)] - 1) * (now.w + 1), tot++;
        merge(now.fm, now.to);
    }
    return (tot == n - 1 ? ret : inf);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        edges.clear();
        for (int i = 1; i <= n - 1; i++){
            int fm, to, w;
            cin >> fm >> to >> w;
            edges.push_back({fm, to, w});
        }
        int ret = kruskal();
        cout << ret << endl;
    }
    return 0;
}