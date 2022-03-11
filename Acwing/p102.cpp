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
const long double eps = 1e-6;
int a[maxn], n, k;

long double pre[maxn];
bool check(long double x){
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + a[i] - x;
    long double tmp = 0;
    for (int i = k; i <= n; i++){
        tmp = min(tmp, pre[i - k]);
        if(pre[i] - tmp >= 0)
            return true;
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long double left = 1, right = 2000;
    while(abs(left - right) > eps){
        long double mid = (left + right) / 2;
        if(check(mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << (int)(right * 1000) << endl;
    return 0;
}