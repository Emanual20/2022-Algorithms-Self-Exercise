/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
ll k, n, ans, res, tot, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    
    queue<ll> q;
    for (ll i = n; i >= 1; i--){
        ll tmp = ceil(max(0ll, a[i] - res) * 1.0f / min(i, k));
        res += tmp * min(i, k);
        tot += tmp, ans += tmp;
        res -= tot;
        q.push(tmp);
        if(q.size() >= k)
            tot -= q.front(), q.pop();
    }

    cout << ans << endl;
    return 0;
}