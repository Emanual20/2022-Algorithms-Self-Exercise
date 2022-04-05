/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;

struct edge{
    int to, w;
};

vector<edge> edges[maxn];

int n, dp;

void dfs(int now, int fm){
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            dp += nw;
            dfs(nto, now);
        }
    }
}

int ans[maxn], k = inf;
void dfs2(int now, int fm){
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            ans[nto] = ans[now] + (-2 * nw + 1);
            dfs2(nto, now);
        }
    }
    k = min(k, ans[now]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back({to, 0}), edges[to].push_back({fm, 1});
    }

    dfs(1, -1);
    ans[1] = dp;
    dfs2(1, -1);
    cout << k << endl;
    for (int i = 1; i <= n; i++){
        if(ans[i] == k){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
/*
6
1 4
2 4
3 4
4 5
4 6
*/