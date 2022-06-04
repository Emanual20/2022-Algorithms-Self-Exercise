/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 250000 + 10;
int n, q, k, x, st[maxn];
ll dp[maxn];
struct edge{
    int to, w;
};
vector<edge> edges[maxn];

void dfs(int now, int fm){
    for(auto &it : edges[now]){
        int nto = it.to, nw = it.w;
        if(nto != fm){
            dfs(nto, now);
            if(st[nto]){
                dp[now] += nw;
            }
            else
                dp[now] += min(1ll * nw, dp[nto]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int nfm, nto, nw;
        cin >> nfm >> nto >> nw;
        edges[nfm].push_back({nto, nw}), edges[nto].push_back({nfm, nw});
    }

    cin >> q;
    while(q--){
        cin >> k;
        vector<int> vec(k, 0);
        for (int i = 0; i < k; i++){
            cin >> vec[i];
            st[vec[i]] = 1;
        }
        dfs(1, -1);
        cout << dp[1] << endl;
        
        for(auto &it : vec)
            st[it] = 0;
        for (int i = 0; i <= n; i++)
            dp[i] = 0;
    }
    return 0;
}