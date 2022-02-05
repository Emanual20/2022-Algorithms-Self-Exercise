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
int t, n;
int dp[maxn][2], a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        dp[0][0] = 0, dp[0][1] = a[0];
        for (int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}