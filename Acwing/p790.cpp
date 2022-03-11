/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const long double eps = 1e-12;
long double n;
bool check(long double x){
    return x * x * x <= n;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long double l = -100, r = 100;
    while(abs(l - r) > eps){
        long double mid = (l + r) / 2;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << fixed << setprecision(8) << r << endl;
    return 0;
}