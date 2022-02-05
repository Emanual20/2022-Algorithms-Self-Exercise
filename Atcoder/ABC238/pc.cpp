/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20 + 10;
const ll MOD = 998244353;
ll n, pre[maxn], base[maxn];
int digits(ll x){
    int ret = 0;
    while(x){
        ret++;
        x /= 10;
    }
    return ret;
}
void init(){
    base[0] = 1, base[1] = 1;
    for (int i = 2; i <= 19; i++){
        base[i] = base[i - 1] * 10;
        base[i] %= MOD;
    }
    for (int i = 1; i <= 18; i++){
        ll end = 9 * base[i] % MOD;
        pre[i] = (1 + end) * end / 2 % MOD;
    }

    // for (int i = 1; i <= 18; i++){
    //     cout << base[i] << " " << pre[i] << endl;
    // }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    while(cin >> n){
        int len = digits(n);
        ll ret = 0;
        for (int i = 1; i < len; i++){
            ret += pre[i];
            ret %= MOD;
        }
        ll now = (n % MOD - base[len] + 1 + MOD) % MOD;
        ret += now * (now + 1) / 2 % MOD;
        ret %= MOD;
        cout << ret << endl;
    }
    return 0;
}