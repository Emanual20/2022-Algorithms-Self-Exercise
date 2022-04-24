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
ll t, n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<ll> a(n, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = a[n - 1] * 2 + 1;
        ll left = a[n - 1], right = a[n - 1];
        for (int i = n - 2; i >= 0; i--){
            if(left < right){
                right = a[i];
            }
            else
                left = a[i];
            ans += ((i == 0 ? 0 : a[i]) + 1);
        }
        cout << (m >= ans ? "YES" : "NO") << "\n";
    }
    return 0;
}