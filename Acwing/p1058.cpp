/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, a[maxn], f[maxn][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(f, -0x3f, sizeof(f));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++){
        f[i][0] = max(f[i - 1][2], f[i - 1][0]);
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - a[i]);
        f[i][2] = f[i - 1][1] + a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, f[i][2]);
    }
    cout << ans << endl;
    return 0;
}