/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
const ll inf = 0x3f3f3f3f3f3f;
ll n, m;
ll a[maxn], pre[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int left = 0, right = 0;
    ll ans = -inf;
    for (int i = 1; i <= n; i++){
        right = i;
        while(a[left] < 0 && left < right)
            left++;
        while(right - left + 1 > m)
            left++;
        ans = max(ans, pre[right] - pre[left - 1]);
    }
    cout << ans << endl;
    return 0;
}