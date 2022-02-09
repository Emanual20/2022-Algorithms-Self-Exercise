/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e2 + 10;
const int inf = 0x3f3f3f3f;
const ll MOD = 998244353;
int dp[maxn][maxn][maxn];
int p[maxn], q[maxn], a[maxn], n, k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    for (int i = 0; i < n; i++){
        cin >> q[i];
    }
    for (int i = 0; i < n; i++){
        a[p[i]] = q[i];
    }
    dp[0][0][n + 1] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= min(i, k); j++){
            for (int bound = 1; bound <= n + 1; bound++){
                if(bound == a[i]){
                    for (int _ = a[i] + 1; _ <= n + 1; _++){
                        dp[i][j][bound] += dp[i - 1][j][_];
                        dp[i][j][bound] %= MOD;
                    }
                }
                else if(bound < a[i]){
                    dp[i][j][bound] = dp[i - 1][j][bound];
                }
                else if(bound > a[i]){
                    dp[i][j][bound] = j >= 1 ? dp[i - 1][j - 1][bound] : 0;
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n + 1; i++){
        ans += dp[n][k][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
/*
3 3
1 2 3
3 2 1

3 2
1 2 3
3 2 1
*/