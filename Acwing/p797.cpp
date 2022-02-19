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
int n, q, a[maxn], d[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++){
        int l, r, c;
        cin >> l >> r >> c;
        d[l] += c, d[r + 1] -= c;
    }
    for (int i = 1; i <= n; i++){
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= n; i++){
        cout << a[i] + d[i] << " ";
    }
    cout << endl;
    return 0;
}