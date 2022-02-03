/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 21;
const int maxm = 1 << 21;
// why we need the first dimension, cuz hamilton trace regulate us to 
int dp[maxn][maxm], a[maxn][maxn], n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][1] = 0;
    // for (int i = 0; i < n; i++){
    //     dp[i][1 << i] = 0;
    // }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int fm = 0; fm < n; fm++)
        {
            if (i & (1 << fm))
            {
                for (int to = 0; to < n; to++)
                {
                    if (fm != to && i & (1 << to))
                    {
                        dp[to][i] = min(dp[to][i], dp[fm][i ^ (1 << to)] + a[fm][to]);
                    }
                }
            }
        }
    }

    // int ans = 0x3f3f3f3f;
    // for (int i = 1; i < n; i++){
    //     ans = min(ans, dp[i][(1 << n) - 1]);
    // }
    // cout << ans << endl;
    cout << dp[n - 1][(1 << n) - 1] << endl;
    return 0;
}