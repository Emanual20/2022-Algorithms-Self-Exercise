/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int x, y, k, b;

ll MOD = 998244353;
ll fac[maxn], inv[maxn], n;
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
/*
* When 1 <= m <= n <= 1e5, we usually use this func
*/
ll regular_C(ll m, ll n){
    if(m > n) return 0;
    if(m == n) return 1;
    return fac[n] * inv[n - m] % MOD * inv[m] % MOD;
}

/*
* When n, m are both enormous(m <= n <= 1e18), when p is a small prime(p < 1e5):
*   We use Lucas theorem.
*/
ll C(ll m, ll n){
    if(m <= MOD && n <= MOD)
        return regular_C(m, n) % MOD;
    return C(m % MOD, n % MOD) * C(m / MOD, n / MOD) % MOD;
}

int solve(int tmp){
    vector<int> vec;
    while(tmp){
        vec.push_back(tmp % b), tmp /= b;
    }

    int ret = 0, res = k;
    for (int i = vec.size() - 1; i >= 0; i--){
        // putting ith to 0th digit
        if(vec[i] >= 2){
            ret += res >= 0 ? C(res, i + 1) : 0;
            break;
        }
        else if(vec[i] == 1){
            // putting 0 in ith digit
            ret += res >= 0 ? C(res, i) : 0;
            // putting 1 in ith digit
            res -= 1;
        }
        else{
            // do nothing
        }

        if(!i && res == 0){
            ret++;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y >> k >> b;
    init();
    cout << solve(y) - solve(x - 1) << endl;
    return 0;
}