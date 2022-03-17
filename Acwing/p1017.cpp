/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int a[maxn], dp[maxn], t, n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i - 1; j++){
                if(a[i] > a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= i - 1; j++){
                if(a[i] < a[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}