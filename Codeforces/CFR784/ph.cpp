/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll t, n, k, a[maxn], w[32], v[32];

void init(){
    w[0] = 1;
    for (int i = 1; i <= 30; i++){
        w[i] = w[i - 1] * 2;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    init();
    while(t--){
        cin >> n >> k;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= 30; j++){
                v[j] += ((a[i] >> j) & 1);
            }
        }
        ll ans = 0;
        for (int i = 30; i >= 0; i--){
            v[i] = n - v[i];
            if(k >= v[i]){
                ans += w[i], k -= v[i];
            }
        }
        cout << ans << "\n";

        for (int i = 0; i <= 30; i++){
            v[i] = 0;
        }
    }
    return 0;
}