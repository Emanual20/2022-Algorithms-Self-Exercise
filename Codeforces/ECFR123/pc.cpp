/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
const ll inf = 0x3f3f3f3f3f3f;
ll a[maxn], pre[maxn], n, x, t;
ll ans[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(ans, 0, sizeof(ans));
        memset(pre, 0, sizeof(pre));

        cin >> n >> x;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }

        for (int left = 1; left <= n; left++){
            for (int right = left; right <= n; right++){
                ll now = pre[right] - pre[left - 1], len = right - left + 1;
                ans[len] = max(ans[len], now + x * len);
            }
        }

        for (int i = 1; i <= n; i++){
            ans[i] = max(ans[i], ans[i - 1]);
        }

        for (int i = n - 1; i >= 0; i--){
            ans[i] = max(ans[i], ans[i + 1] - x);
        }

        for (int i = 0; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}