/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int t, n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            a[i] = (x != 0);
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++){
            ans = ans + i * (n + 1 - i);
        }

        for (int i = 0; i < n; i++){
            for (int j = i; j < n; j++){
                for (int k = i; k <= j; k++){
                    ans = ans + (a[k] == 0);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}