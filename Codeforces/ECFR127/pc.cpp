/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-22
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
ll n, x, a[maxn], pre[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + a[i];
        }
        ll ans = 0, last = 0;
        for (int i = n; i >= 1; i--){
            if(pre[i] + last * i <= x){
                ll tmp = (x - pre[i]) / i;
                ans += (tmp - last + 1) * i;
                last = tmp + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}