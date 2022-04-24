/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-22
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

bool check(int tmp){
    int ret = 1;
    for (int i = 1; i <= n; i++){
        ret = ret && (abs(tmp + i - 1 - a[i]) <= 1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = check(a[1] - 1) || check(a[1]) || check(a[1] + 1);
        cout << (ans ? "YES\n" : "NO\n");
    }
    return 0;
}