/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
struct node{
    int index;
    vector<int> seq;
};
node nodes[maxn];
int n, q, w[maxn];
struct edge{
    int fm, to;
};
bool comp(int ni1, int ni2){
    return ni1 > ni2;
}
vector<edge> edges[maxn];
void dfs(int now, int fm){
    vector<int> tmp;
    tmp.push_back(w[now]);
    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(nto != fm){
            dfs(nto, now);
            for(auto ele : nodes[nto].seq){
                tmp.push_back(ele);
            }
        }
    }
    sort(tmp.begin(), tmp.end(), comp);
    int iter = min(20, (int)tmp.size());
    nodes[now].seq.clear();
    for (int i = 0; i < iter; i++){
        nodes[now].seq.push_back(tmp[i]);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i < n; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back({fm, to}), edges[to].push_back({to, fm});
    }

    dfs(1, -1);
    for (int i = 1; i <= q; i++){
        int v, k;
        cin >> v >> k;
        cout << nodes[v].seq[k - 1] << endl;
    }
    return 0;
}