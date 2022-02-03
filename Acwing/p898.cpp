/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 10;
const int inf = 0x3f3f3f3f;
int n, a[maxn][maxn], dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> a[i][j];
        }
    }

    dp[0][0] = a[0][0];
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= i; j++){
            dp[i][j] = max((j - 1 >= 0 && j - 1 <= i - 1 ? dp[i - 1][j - 1] : -inf), 
                            j <= i - 1 ? dp[i - 1][j] : -inf) 
                    + a[i][j];
        }
    }

    int ans = -inf;
    for (int i = 0; i < n; i++){
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << endl;
    return 0;
}