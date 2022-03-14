/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1500 + 10;
const int inf = 0x3f3f3f3f;
int n, m, w[maxn], dp[maxn][3];
vector<int> edges[maxn];

void dfs(int now, int fm){
    for(auto &iter : edges[now]){
        if(iter != fm){
            dfs(iter, now);
        }
    }

    dp[now][0] = 0, dp[now][1] = inf, dp[now][2] = w[now];
    for(auto &iter : edges[now]){
        if(iter != fm){
            dp[now][0] += min(dp[iter][1], dp[iter][2]);
            dp[now][2] += min(dp[iter][0], min(dp[iter][1], dp[iter][2]));
        }
    }

    for(auto &iter : edges[now]){
        if(iter != fm){
            dp[now][1] = min(dp[now][1], dp[now][0] - min(dp[iter][1], dp[iter][2]) + dp[iter][2]);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        int now; cin >> now; cin >> w[now] >> m;
        for (int j = 1; j <= m; j++){
            int x;
            cin >> x;
            edges[x].push_back(now), edges[now].push_back(x);
        }
    }

    dfs(1, -1);
    cout << min(dp[1][1], dp[1][2]) << endl;
    return 0;
}