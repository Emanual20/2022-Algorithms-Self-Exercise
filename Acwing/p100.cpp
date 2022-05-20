/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
int n;
ll a[maxn], b[maxn];

const ll MOD = 1e9 + 7;
ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    ll negtot = 0, postot = 0;
    for (int i = 2; i <= n; i++){
        if(b[i] < 0)
            negtot += -b[i];
        else
            postot += b[i];
    }

    ll ans1 = max(negtot, postot);
    ll ans2 = min(negtot, postot);
    ans2 = ans1 - ans2 + 1;
    cout << ans1 << endl
         << ans2 << endl;
    return 0;
}