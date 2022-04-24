/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
int n, a[maxn], dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[n + i] = a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int len = 1; len < n; len++){
        for (int j = 1; j + len < 2 * n; j++){
            for (int k = j; k < j + len; k++){
                dp[j][j + len] = max(dp[j][j + len],
                                     dp[j][k] + dp[k + 1][j + len] + a[j] * a[k + 1] * a[j + len + 1]);
            }
        }
    }

    int ans = 0;
    for (int j = 1; j + n - 1 < 2 * n; j++){
        ans = max(ans, dp[j][j + n - 1]);
    }
    cout << ans << endl;
    return 0;
}