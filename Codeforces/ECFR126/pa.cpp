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
const int maxn = 30 + 10;
int t, n, a[maxn], b[maxn], resa[maxn], resb[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> b[i];
            resa[i] = min(a[i], b[i]), resb[i] = max(a[i], b[i]);
        }

        ll ans = 0;
        for (int i = 1; i < n; i++){
            ans += abs(resa[i] - resa[i + 1]);
            ans += abs(resb[i] - resb[i + 1]);
        }
        cout << ans << endl;
    }
    return 0;
}