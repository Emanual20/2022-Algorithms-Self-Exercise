/**
 * @file template.cpp
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
const int maxn = 20 + 10;
int a[maxn][maxn], dp[maxn][maxn][maxn], n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int x, y, w;
    while(cin >> x >> y >> w, x + y + w){
        a[x][y] = w;
    }

    memset(dp, 0, sizeof(dp));
    dp[2][1][1] = a[1][1];
    for (int k = 3; k <= 2 * n; k++){
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
    
    cout << dp[2 * n][n][n];
    return 0;
}