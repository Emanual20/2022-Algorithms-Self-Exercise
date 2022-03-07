/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
ll calc_1(ll x){
    int ret = 0;
    while(x){
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}
ll items[15];
void init_items(){
    items[0] = 1;
    for (int i = 1; i < 15; i++){
        items[i] = items[i - 1] * i;
    }
}
ll consume(ll n, ll x){
    for (int i = 1; i < 15; i++){
        if(x & (1 << i))
            n -= items[i];
    }
    return n;
}
ll t, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    init_items();
    cin >> t;
    while(t--){
        cin >> n;
        ll ans = inf;
        for (int i = 0; i < (1 << 15); i++){
            ll rem = consume(n, i);
            if(rem >= 0){
                ans = min(ans, calc_1(i) + calc_1(rem));
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

// 1, 2, 4, 8, 16, 32, ..., 2^40 (41 items)
// 1, 2, 6, 24, 120, 720, ..., 14! (15 items)
// v = 1e12, wi = 1 exactly full 