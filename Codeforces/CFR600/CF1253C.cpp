/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
int n, m;
ll a[maxn], pre[maxn], ans[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++){
        if(i - m >= 0)
            ans[i] = ans[i - m] + pre[i];
        else
            ans[i] = pre[i];
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}