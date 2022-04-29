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
const int maxn = 100 + 10;
// dp[i][j] means node i keep j edges remaining 
int dp[maxn][maxn], n, k;

struct edge{
    int to, w;
};
vector<edge> edges[maxn];

void dfs(int now, int fm){
    for(auto &iter : edges[now]){
        int nto = iter.to, nw = iter.w;
        if(nto != fm){
            dfs(nto, now);
            for (int i = k; i >= 0; i--){// enumerate v = k...0, ensure each item can be selected only once
                for (int j = 0; j <= min(i - 1, k); j++){// enumerate item = 0...i-1
                    if(i - j - 1 >= 0)
                        dp[now][i] = max(dp[now][i], dp[nto][j] + dp[now][i - j - 1] + nw);
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        edges[fm].push_back({to, w}), edges[to].push_back({fm, w});
    }
    memset(dp, 0, sizeof(dp));
    dfs(1, -1);
    cout << dp[1][k] << endl;
    return 0;
}