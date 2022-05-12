/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n;

struct item{
    int x, y;
};

item dp[maxn][2];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;

        for (int i = 0; i <= n; i++){
            dp[i][0].x = dp[i][0].y = 0;
            dp[i][1].x = dp[i][1].x = 0;
        }
        dp[0][0].y = 1, dp[0][1].y = 1;

        for (int i = 2; i <= n; i += 2){
            if(dp[i - 2][0].x < dp[i - 2][1].x){
                dp[i][0].y = dp[i - 2][0].y;
                dp[i][1].y = dp[i - 2][0].y + 1;
            }
            else if(dp[i - 2][0].x > dp[i - 2][1].x){
                dp[i][0].y = dp[i - 2][1].y + 1;
                dp[i][1].y = dp[i - 2][1].y;
            }
            else{
                dp[i][0].y = min(dp[i - 2][0].y, dp[i - 2][1].y + 1);
                dp[i][1].y = min(dp[i - 2][0].y + 1, dp[i - 2][1].y);
            }
            dp[i][0].x = min(dp[i - 2][0].x, dp[i - 2][1].x) + (s[i - 1] != '0') + (s[i - 2] != '0');
            dp[i][1].x = min(dp[i - 2][0].x, dp[i - 2][1].x) + (s[i - 1] != '1') + (s[i - 2] != '1');
        }

        int rem = 0;
        if(dp[n][0].x < dp[n][1].x)
            rem = dp[n][0].y;
        else if(dp[n][0].x > dp[n][1].x)
            rem = dp[n][1].y;
        else
            rem = min(dp[n][0].y, dp[n][1].y);

        cout << min(dp[n][0].x, dp[n][1].x) << " " << rem << "\n";
    }
    return 0;
}