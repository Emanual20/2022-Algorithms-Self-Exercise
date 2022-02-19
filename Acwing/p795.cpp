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
const int maxn = 1e5 + 10;
int pre[maxn], a[maxn];
int n, q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
    return 0;
}