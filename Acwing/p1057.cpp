/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxk = 1e2 + 10;
const int inf = 0x3f3f3f3f;
int dp[maxk][maxn][2], n, k, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 0; i <= k; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j][0] = max(dp[i][j-1][0], i > 0 ? dp[i - 1][j - 1][1] + a[j] : -inf);
            dp[i][j][1] = max(dp[i][j - 1][1], dp[i][j - 1][0] - a[j]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= k; i++){
        for (int j = 1; j <= n; j++){
            ans = max(ans, dp[i][j][0]);
        }
    }
    cout << ans << endl;
    return 0;
}