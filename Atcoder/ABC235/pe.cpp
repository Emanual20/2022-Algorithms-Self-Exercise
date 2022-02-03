/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e5 + 10;
int n, m, q, f[maxn], ans[maxn];
struct edge{
    int index;
    int fm, to, w;
};
bool comp(edge e1, edge e2){
    if(e1.w == e2.w)
        return e1.index > e2.index;
    return e1.w < e2.w;
}
vector<edge> edges;
int find(int k){
    if(f[k] == k)
        return k;
    return f[k] = find(f[k]);
}
int merge(int des, int res){
    int a = find(des), b = find(res);
    f[b] = a; return 0;
}
void kruskal(){
    // kruskal init
    for (int i = 0; i < n; i++){
        f[i] = i;
    }
    // sorted the edges
    sort(edges.begin(), edges.end(), comp);
    // try to link all edges
    for (int i = 0; i < edges.size(); i++){
        edge e_now = edges[i];
        if(find(e_now.fm) != find(e_now.to)){
            e_now.index == -1 ? merge(e_now.fm, e_now.to) : ans[e_now.index] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges.push_back({-1, fm, to, w});
    }
    for (int i = 0; i < q; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges.push_back({i, fm, to, w});
    }

    kruskal();

    for (int i = 0; i < q; i++){
        if(ans[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}