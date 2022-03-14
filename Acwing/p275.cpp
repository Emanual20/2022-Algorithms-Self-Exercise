/**
 * @file AcWing 275 [NOIP2008]
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int a[maxn][maxn], dp[maxn][maxn][maxn], n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[2][1][1] = a[1][1];
    for (int k = 3; k <= n + m; k++){
        for (int i = 1; i <= min(k, n); i++){
            for (int j = 1; j <= min(k, n); j++){
                // dp[k][i][j] means: route1 (1, 1)->(i, k - i); route2 (1, 1)->(j, k - j)
                // route1 : right, route2 : right
                dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j]);
                // route1 : right, route2 : down
                dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i][j - 1]);
                // route1 : down, route2 : right
                dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j]);
                // route1 : down, route2 : down
                dp[k][i][j] = max(dp[k][i][j], dp[k - 1][i - 1][j - 1]);
                // fetch this number
                dp[k][i][j] += (i == j ? a[i][k - i] : a[i][k - i] + a[j][k - j]);
            }
        }
    }
    
    cout << dp[n + m][n][n];
    return 0;
}