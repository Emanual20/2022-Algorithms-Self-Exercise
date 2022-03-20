/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
ll t, n, k, x;
multiset<ll> st;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        st.clear();
        st.insert(-inf), st.insert(inf);
        for (int i = 1; i <= k; i++){
            cin >> x;
            st.insert(x);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++){
            auto iter_r = st.lower_bound(i);
            auto iter_l = iter_r--;
            ll tmp = min(*iter_r - i + 1, i - *iter_l + 1);
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
}