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
const int maxn = 2e5 + 10;
int t;
ll l, r, a;
ll solve(ll x){
    return x / a + x % a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> l >> r >> a;
        ll ans = 0;
        if(r - r % a - 1 >= l){
            ans = max(solve(r - r % a - 1), max(solve(l), solve(r)));
        }
        else{
            ans = max(solve(l), solve(r));
        }
        cout << ans << '\n';
    }
    return 0;
}