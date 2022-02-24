/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x;
    cin >> x;
    long double tmp = x * x + 12800000 * x;
    cout << fixed << setprecision(4) << sqrt(tmp) << endl;
    return 0;
}