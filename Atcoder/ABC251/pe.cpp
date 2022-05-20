/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-17
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

const int maxn = 3e5 + 10;
int n, a[maxn];
ll dp[maxn][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 0;
    for (int i = 2; i <= n + 1; i++){
        // index i corresponding to cost a[i - 1]
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 2][1], min(dp[i - 1][0], dp[i - 1][1])) + a[i - 1];
    }

    ll ans = dp[n][1];
    memset(dp, 0x3f, sizeof(dp));
    dp[0][1] = 0, dp[1][0] = 0, dp[1][1] = 0;
    for (int i = 2; i <= n + 1; i++){
        // index i corresponding to cost a[i - 1]
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min(dp[i - 2][1], min(dp[i - 1][0], dp[i - 1][1])) + a[i - 1];
    }
    ans = min(ans, dp[n + 1][1]);

    cout << ans << endl;
    return 0;
}