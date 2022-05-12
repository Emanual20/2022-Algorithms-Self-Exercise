/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5 + 10;
ull pre[maxn], mulp[maxn];
string s;
int n, q, p = 131;

void init(){
    pre[0] = 1, mulp[0] = 1;
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] * p + (s[i - 1] - 'a' + 1);
        mulp[i] = mulp[i - 1] * p;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q >> s;
    init();
    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ull res1 = pre[r1] - pre[l1 - 1] * mulp[r1 - l1 + 1];
        ull res2 = pre[r2] - pre[l2 - 1] * mulp[r2 - l2 + 1];
        cout << (res1 == res2 ? "Yes\n" : "No\n");
    }
    return 0;
}