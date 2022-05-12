/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200 + 10;
const ll inf = 0x3f3f3f3f3f3f;

ll dp[maxn][maxn][maxn], a[maxn];
int n, k, x;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    memset(dp, -0x3f, sizeof(dp));
    for (int i = 0; i <= k - 1; i++){
        dp[0][i][i] = 0;
    }
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= n; j++){
            // calc dp[i][j][...]
            // if choose a[j]
            for (int q = 0; q <= k - 1; q++){
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][q] + a[j]);
            }
            // if not choose a[j]
            for (int q = 0; q <= k - 2; q++){
                dp[i][j][q + 1] = max(dp[i][j][q + 1], dp[i][j - 1][q]);
            }
        }
    }

    ll ans = -1;
    for (int i = 0; i < k; i++){
        ans = max(ans, dp[x][n][i]);
    }
    cout << ans << endl;
    return 0;
}  