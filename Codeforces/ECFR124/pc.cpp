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
const int maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f;
ll t, n, a[maxn], b[maxn];

ll dis(int ida, int idb){
    return abs(a[ida] - b[idb]);
}

ll solve(){
    ll ret = inf;

    ll min_1i = inf, min_ni = inf, min_i1 = inf, min_in = inf;
    for (int i = 1; i <= n; i++){
        min_1i = min(min_1i, dis(1, i));
        min_ni = min(min_ni, dis(n, i));
        min_i1 = min(min_i1, dis(i, 1));
        min_in = min(min_in, dis(i, n));
    }

    // 3 lines
    ret = min(ret, dis(1, 1) + min_ni + min_in);
    ret = min(ret, dis(1, n) + min_ni + min_i1);
    ret = min(ret, dis(n, 1) + min_1i + min_in);
    ret = min(ret, dis(n, n) + min_i1 + min_1i);
    ret = min(ret, dis(1, n) + dis(n, n) + min_i1);
    ret = min(ret, dis(1, 1) + dis(n, 1) + min_in);
    ret = min(ret, dis(1, 1) + dis(1, n) + min_ni);
    ret = min(ret, dis(n, 1) + dis(n, n) + min_1i);
    // 4 lines
    ret = min(ret, min_1i + min_ni + min_i1 + min_in);
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
        }
        ll ans = dis(1, 1) + dis(n, n);
        ans = min(ans, dis(1, n) + dis(n, 1));

        // 3 or 4 lines
        ans = min(ans, solve());
        cout << ans << endl;
    }
    return 0;
}