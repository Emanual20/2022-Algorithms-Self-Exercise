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
typedef long long ll;
const ll MOD = 200907;
const int maxn = 2e5 + 10;
ll t, a, b, c, k, ans;
ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1)
            ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b >> c >> k;
        if(b - a == c - b){
            ans = a + (b - a) * (k - 1);
        }
        else if(b / a == c / b){
            ans = a * quickpow(b / a, k - 1);
        }
        cout << ans % MOD << endl;
    }
    return 0;
}