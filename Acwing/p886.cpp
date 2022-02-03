/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 1e3;
const ll MOD = 1e9 + 7;
ll fac[maxn], inv[maxn], n, k;
vector<ll> items;
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
void init(){
    fac[0] = 1, fac[1] = 1;
    for (int i = 2; i < maxn; i++){
        fac[i] = fac[i - 1] * i % MOD;
    }
    // a * a^(p-2) === 1(mod p)
    for (int i = 0; i < maxn; i++){
        inv[i] = quickpow(fac[i], MOD - 2);
    }
}
ll C(ll m, ll n){
    return fac[n] * inv[n - m] % MOD * inv[m] % MOD;
}
// ll C(ll m, ll n){
//     if(m > n)
//         return 0;
//     ll ret = 1;
//     for (ll i = 0; i < m; i++){
//         ret *= (n - i);
//         ret %= MOD;
//     }
//     return ret * inv[m] % MOD;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin>>n;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin>>x>>y;
        cout<<C(y, x)<<endl;
    }
    return 0;
}