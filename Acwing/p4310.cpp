/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<int> edges[maxn];
int n, q, ans[maxn], sz[maxn];
vector<int> seq;

void dfs1(int src){
    seq.push_back(src);
    sz[src] = 1;
    for(auto &iter : edges[src]){
        dfs1(iter);
        sz[src] += sz[iter];
    }
}
int w[maxn];

struct query{
    int index;
    int u, k;
};
vector<query> queries;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 2; i <= n; i++){
        int x;
        cin >> x;
        edges[x].push_back(i);
    }

    dfs1(1);

    for (int i = 0; i < seq.size(); i++){
        w[seq[i]] = i;
    }

    for (int i = 1; i <= q; i++){
        int nu, nk;
        cin >> nu >> nk;
        if(w[nu] + nk - 1 > n || nk > sz[nu]){
            cout << -1 << '\n';
        }
        else{
            cout << seq[w[nu] + nk - 1] << '\n';
        }
    }
    return 0;
}