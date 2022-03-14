/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1500 + 10;
int n;
vector<int> edges[maxn];

int dp[maxn][2];
void dfs(int now, int fm){
    dp[now][0] = 1, dp[now][1] = 0;
    for(auto &iter : edges[now]){
        if(iter != fm){
            dfs(iter, now);
            // 0 means node now puts a human
            dp[now][0] += min(dp[iter][0], dp[iter][1]);
            // 1 means node now puts no human
            dp[now][1] += dp[iter][0];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(~scanf("%d", &n)){
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            int x, cnt, tmp;
            scanf("%d:(%d)", &x, &cnt);
            for (int j = 1; j <= cnt; j++){
                scanf("%d", &tmp);
                edges[x].push_back(tmp), edges[tmp].push_back(x);
            }
        }

        dfs(1, -1);
        cout << min(dp[1][0], dp[1][1]) << "\n";
        for (int i = 0; i < n; i++){
            edges[i].clear();
        }
    }
    return 0;
}