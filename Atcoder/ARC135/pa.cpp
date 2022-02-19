/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll x, answer = 1;
vector<ll> ans;
queue<ll> q;
map<ll, ll> res;
ll solve(ll x){
    if(res.count(x)){
        return res[x];
    }

    ll ret = 1;

    ll now = x;
    ll num1 = now / 2, num2 = (now + 1) / 2;
    if(!res.count(num1)){
        solve(num1);
    }
    ret *= res[num1];
    ret %= MOD;

    if(!res.count(num2)){
        solve(num2);
    }
    ret *= res[num2];
    ret %= MOD;

    return res[x] = ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    res[1] = 1, res[2] = 2, res[3] = 3, res[4] = 4;
    ll answer = solve(x);
    cout << answer << endl;
    return 0;
}