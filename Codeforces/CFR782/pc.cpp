/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-18
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
ll n, a, b, x[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        for (int i = 1; i <= n; i++){
            cin >> x[i];
        }

        ll last = 0, now = 0, ans = 0;
        for (int i = 1; i <= n; i++){
            ll tmp = - (last - now) * b * (n - i + 1) 
                     + (last - now) * a;
            
            if(tmp >= 0){
                ans += (x[i] - now) * b;
            }
            else{
                ans += (last - now) * a;
                now = last;
                ans += (x[i] - last) * b;
            }
            last = x[i];
        }
        cout << ans << endl;
    }
    return 0;
}