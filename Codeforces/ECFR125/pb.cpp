/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll t, n, b, x, y, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> b >> x >> y;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            if(a[i - 1] + x > b){
                a[i] = a[i - 1] - y;
            }
            else
                a[i] = a[i - 1] + x;
            ans += a[i];
        }
        cout << ans << endl;
    }
    return 0;
}