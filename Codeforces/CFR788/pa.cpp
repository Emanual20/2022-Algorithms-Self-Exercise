/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int tot = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            tot += (a[i] < 0);
            a[i] = abs(a[i]);
        }

        for (int i = 1; i <= tot; i++){
            a[i] = -a[i];
        }

        int flag = 1;
        for (int i = 1; i < n; i++){
            flag = flag && (a[i] <= a[i + 1]);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}