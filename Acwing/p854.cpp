/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e2 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn], edges[maxn][maxn], n, m, q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        dp[fm][to] = min(dp[fm][to], w);
    }
    for (int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(q--){
        int fm, to;
        cin >> fm >> to;
        if(dp[fm][to] > inf / 2){
            cout << "impossible" << endl;
        }
        else{
            cout << dp[fm][to] << endl;
        }
    }
}