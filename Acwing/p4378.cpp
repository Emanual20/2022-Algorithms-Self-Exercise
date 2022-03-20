/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
ll n, m, k, a[maxn], pre[maxn];
ll dp[maxn][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= k; i++){
        ll ndp[maxn][2];
        memset(ndp, 0, sizeof(ndp));
        for (int j = 1; j <= n; j++){
            ndp[j][0] = max(ndp[j - 1][0], ndp[j - 1][1]);
            if(j >= m) ndp[j][1] = max(dp[j - m][0], dp[j - m][1]) + (pre[j] - pre[j - m]);
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}