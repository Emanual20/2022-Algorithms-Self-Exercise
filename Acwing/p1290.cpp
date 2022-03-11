/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;

typedef long long ll;
const ll MOD = 1e5 + 3;
ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret % MOD;
}

ll m, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>m>>n){
        m %= MOD;
        ll ans = quickpow(m, n) - quickpow(m - 1, n - 1) * m % MOD;
        cout << (ans + MOD) % MOD << endl;
    }
    return 0;
}