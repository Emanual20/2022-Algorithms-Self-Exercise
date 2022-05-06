/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int q;
string s, t;

int calc_a(string tmp){
    int ret = 0;
    for(auto &ch : tmp){
        ret += (ch == 'a');
    }
    return ret;
}

ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base;
        base *= base;
        index >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> q;
    while(q--){
        cin >> s >> t;
        int stota = calc_a(s), ttota = calc_a(t);
        if(t == "a"){
            cout << 1 << "\n";
        }
        else if(ttota >= 1){
            cout << -1 << "\n";
        }
        else{
            ll ans = quickpow(2, stota);
            cout << ans << "\n";
        }
    }
    return 0;
}