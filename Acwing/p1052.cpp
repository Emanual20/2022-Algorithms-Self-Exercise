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
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
ll dp[maxn][2], n, ans = 1;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    if(n <= s.length()){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++){
        ans *= 26;
        ans %= MOD;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n - s.length() + 1; i++){
        dp[i][0] = (dp[i - 1][0] * 26) % MOD;
        dp[i][1] = (dp[i - 1][0] * 1 + dp[i - 1][1] * 26) % MOD;
    }
    ans = (ans + MOD - dp[n - s.length() + 1][1]) % MOD;
    cout << ans << endl;
    return 0;
}