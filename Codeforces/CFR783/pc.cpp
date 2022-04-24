/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll ans = inf;
    for (int i = 1; i <= n; i++){
        ll res = 0;
        ll last = 0;
        for (int j = i - 1; j >= 1; j--){
            ll tmp = ceil(abs(last - 1) * 1.0 / a[j]);
            last = -tmp * a[j];
            res += tmp;
        }
        last = 0;
        for (int j = i + 1; j <= n; j++){
            ll tmp = ceil(abs(last + 1) * 1.0 / a[j]);
            last = tmp * a[j];
            res += tmp;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}