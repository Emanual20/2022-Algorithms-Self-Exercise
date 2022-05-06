/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, k, root, to, x, a[maxn], dp[maxn], vis[maxn], ans = 0;
vector<int> edges[maxn];

void dfs(int now){
    vis[now] = 1;
    for(auto &iter : edges[now]){
        if(!vis[iter]){
            dp[iter] = dp[now] + 1;
            dfs(iter);
            a[now] |= a[iter];
        }
    }

    if(a[now] == 1 && now != root){
        ans += 1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k >> root >> to;
        for (int i = 1; i <= k; i++){
            cin >> x;
            a[x] = 1;
        }
        a[to] = 1;

        for (int i = 1; i < n; i++){
            int nfm, nto;
            cin >> nfm >> nto;
            edges[nfm].push_back(nto), edges[nto].push_back(nfm);
        }

        ans = 0;
        dfs(root);
        ans = ans * 2;
        ans -= dp[to];
        cout << ans << "\n";

        for (int i = 1; i <= n; i++){
            dp[i] = 0, vis[i] = 0, a[i] = 0;
            edges[i].clear();
        }
    }
    return 0;
}