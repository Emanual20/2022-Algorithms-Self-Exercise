/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const long double pi = 3.1415926;
const long double eps = 1e-6;
ll n, R, r;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> R >> r;

    if(R < r){
        cout << "NO\n";
    }
    else if(R < 2 * r){
        cout << (n <= 1 ? "YES\n" : "NO\n");
    }
    else{
        long double tmp = 2 * asin(r * 1.0 / (R - r));
        ll ans = floor(2 * pi / tmp + eps);
        cout << (ans >= n ? "YES\n" : "NO\n");
    }
    return 0;
}