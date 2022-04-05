/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
const ll MOD = 998244353;
ll dp[maxn], t, n;

void init(){
    dp[1] = 1;
    for (int i = 2; i < maxn; i++){
        dp[i] = dp[i - 1] * i % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    init();
    while(t--){
        cin >> n;
        if(n % 2){
            cout << 0 << endl;
        }
        else{
            ll ans = dp[n / 2] * dp[n / 2] % MOD;
            cout << ans << endl;
        }
    }
    return 0;
}