/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int t, n, a[maxn], suf[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll ans = 0, idx = n, cnt = 0;
        for (int i = 1; i <= n - 1; i++){
            ans += a[i];
            if(a[i] > 0 && idx == n){
                idx = i;
            }
        }
        for (int i = idx; i <= n - 1; i++){
            if(a[i] == 0)
                cnt += 1;
        }
        cout << (ans + cnt) << "\n";
    }
    return 0;
}