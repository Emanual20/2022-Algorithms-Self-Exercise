/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
const ll MOD = 1e9 + 7;
ll n, l, r, z, dp[65][maxn];

ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1)
            ret = ret * base % MOD;
        base = base * base % MOD;
        index >>= 1;
    }
    return ret;
}

ll fac[maxn], inv[maxn], choose[maxn];
/*
* Note that maxn = 2e5 originally, which may cause TLE in some cases.
*/
void init(){
    fac[0] = 1, fac[1] = 1;
    for (int i = 2; i < maxn; i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    // a * a^(p-2) === 1(mod p), when p is a prime
    for (int i = 0; i < maxn; i++){
        inv[i] = quickpow(fac[i], MOD - 2);
    }
}
/*
* When 1 <= m <= n <= 1e5, we usually use this func
*/
ll regular_C(ll m, ll n){
    if(m > n) return 0;
    if(m == n) return 1;
    return fac[n] * inv[n - m] % MOD * inv[m] % MOD;
}

ll solve(ll tmp){
    memset(dp, 0, sizeof(dp));
    // dp[i][j]
    dp[61][0] = 1;
    for (int i = 60; i >= 0; i--){
        int curt = (tmp >> i) & 1;
        int curz = (z >> i) & 1;
        for (int j = 0; j <= n; j++){
            ll rem = 2 * j + curt;
            for (int k = curz; k <= min(n, rem); k += 2){
                ll cur_rem = min(n, rem - k);
                dp[i][cur_rem] += (dp[i + 1][j] * regular_C(k, n)) % MOD;
                dp[i][cur_rem] %= MOD;
            }
        }
    }

    ll ret = 0;
    for (int i = 0; i <= n; i++){
        ret = (ret + dp[0][i]) % MOD;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> l >> r >> z;
    init();
    ll ans = (solve(r) - solve(l - 1) + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}