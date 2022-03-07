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
const int maxn = 1e6 + 10;
const ll MOD = 998244353;
ll dp[maxn][10], n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= 9; i++){
        dp[1][i] = 1;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 9; j++){
            dp[i + 1][j] += dp[i][j], dp[i+1][j] %= MOD;
            dp[i + 1][j - 1] += dp[i][j], dp[i+1][j-1] %= MOD;
            dp[i + 1][j + 1] += dp[i][j], dp[i + 1][j + 1] %= MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 9; i++){
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}