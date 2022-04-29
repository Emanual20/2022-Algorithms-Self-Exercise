/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 10;
ll MOD = 1e9 + 7;
ll fac[maxn], inv[maxn], n, a, b;
ll CN[maxn];
int st[19 * maxn];
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> a >> b >> n;
    if(a > b)
        swap(a, b);
    
    init();

    queue<int> q;
    q.push(0);
    while(!q.empty()){
        auto now = q.front();
        st[now] = 1;
        int tmp1 = now * 10 + a;
        int tmp2 = now * 10 + b;

        if(tmp1 < 18000000){
            q.push(tmp1);
        }
        if(tmp2 < 18000000){
            q.push(tmp2);
        }

        q.pop();
    }

    CN[0] = 1;
    for (int i = 1; i <= n; i++){
        CN[i] = CN[i - 1] * (n + 1 - i);
        CN[i] %= MOD;
        CN[i] *= inv[i];
        CN[i] %= MOD;
    }

    ll ans = 0;
    ll res = n * a - (b - a);
    for (int i = 0; i <= n; i++){
        res += (b - a);
        if(st[res]){
            ans = (ans + CN[i]) % MOD;
        }
    }

    cout << ans << endl;
    return 0;
}