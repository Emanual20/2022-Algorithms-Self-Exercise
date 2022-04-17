/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;

ll t, n;
ll h[maxn], a[maxn];

bool check(ll tmp){
    ll day0 = tmp / 2, day1 = tmp / 2 + tmp % 2;
    vector<ll> inv(n + 1, 0);
    for (int i = 1; i <= n; i++){
        ll res = a[i] / 2;
        inv[i] = min(day0, res) * 2;
        day0 -= min(day0, res);
    }
    ll tot = 0;
    for (int i = 1; i <= n; i++){
        tot += (a[i] - inv[i]);
    }
    return tot <= day1;
}

ll solve(){
    ll left = 0, right = 3e14;
    while(left < right){
        ll mid = left + right >> 1;
        if(check(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        ll maxi = 0;
        for (int i = 1; i <= n; i++){
            cin >> h[i];
            maxi = max(maxi, h[i]);
        }
        for (int i = 1; i <= n; i++){
            a[i] = maxi - h[i];
        }
        ll ans = solve();

        for (int i = 1; i <= n; i++){
            a[i] += 1;
        }
        ans = min(ans, solve());

        cout << ans << "\n";
    }
    return 0;
}