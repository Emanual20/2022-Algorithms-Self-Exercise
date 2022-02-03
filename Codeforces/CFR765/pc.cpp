/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 10;
const int inf = 0x7fffffff;
int n, l, k;
int cord[maxn], limit[maxn], dp[maxn][maxn], ans = inf;
int dist(int fm, int to){
    return cord[to] - cord[fm];
}
int main(){
    memset(dp, 0x3f, sizeof(dp));
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> l >> k;
    for (int i = 0; i < n; i++){
        cin >> cord[i];
    }
    cord[n] = l;
    for (int i = 0; i < n; i++){
        cin >> limit[i];
    }

    /*
    * dp[i][j] denotes:
    *       the minimum cost from the i th sign to the destination with j times deletions exactly with the limitation that
    *       **the i th sign could not be deleted**.
    *
    * Transfer equation:
    *       dp[i][j] = min(dp[i+1][j] + limit[i] * dist(i, i + 1),
    *                      dp[i+2][j-1] + limit[i] * dist(i, i + 2),
    *                      ...
    *                      dp[n-1][j-n+2] + limit[i] * dist(i, n-1))
    * 
    * Q: Why we transfer like this?
    * A: We could ensure that the i th sign could not be deleted, so we can just enumerate the number which denotes 
    *    how many continuous signs after i th sign could be deleted, which makes the limit(in our tranfer equation)
    *    constant. 
    * 
    */
    dp[n][0] = 0;
    dp[n - 1][0] = limit[n - 1] * dist(n - 1, n);
    
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j <= k; j++){
            for (int times = 0; times <= min(n - 1 - i, k); times++){
                dp[i][j] = min(dp[i][j], dp[i + 1 + times][j - times] + limit[i] * dist(i, i + 1 + times));
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    for (int i = 0; i <= k; i++){
        ans = min(ans, dp[0][i]);
    }
    cout << ans << endl;
    return 0;
}