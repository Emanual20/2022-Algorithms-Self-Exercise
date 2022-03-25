/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;

ll dp[maxn], t, n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        if (n % 2) {
            cout << 2 << endl;
            continue;
        }
        ll sum = 1; n *= 2;
        while (n % 2 == 0) {
            n /= 2; sum *= 2;
        }
        if (n > sum) {
            cout << sum << endl;
        } 
        else {
            if (n == 1) {
                cout << -1 << endl;
            } else {
                cout << n << endl;
            }
        }
    }
    return 0;
}