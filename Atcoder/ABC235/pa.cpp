/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a;
    cin>>a;
    int d2 = a / 100 % 10, d1 = a / 10 % 10, d0 = a % 10;
    int ans = 111 * (d2 + d1 + d0);
    cout << ans << endl;

    return 0;
}