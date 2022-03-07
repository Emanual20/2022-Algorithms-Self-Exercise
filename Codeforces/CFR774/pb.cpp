/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<ll> v;
int t, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        v.clear();
        cin >> n;
        ll x;
        for (int i = 1; i <= n; i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        ll num1 = (n + 1) / 2;
        ll num2 = (n - 1) / 2;
        ll sum1 = 0, sum2 = 0;
        for (int i = 0; i < num1; i++){
            sum1 += v[i];
        }
        for (int i = v.size() - 1; i >= v.size() - num2; i--){
            sum2 += v[i];
        }
        cout << (sum1 < sum2 ? "YES" : "NO") << '\n';
    }
    return 0;
}