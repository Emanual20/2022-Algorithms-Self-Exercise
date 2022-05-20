/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-13
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
const int inf = 0x3f3f3f3f;
int dp[maxn][3], n, t;
char a[maxn][2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    memset(dp, 0x3f, sizeof(dp));
    while(t--){
        cin >> n;
        for (int i = 0; i < 2; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[j][i];
            }
        }

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++){
            if(a[i][0] == '.' && a[i][1] == '.'){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = min(dp[i - 1][1] + 1, dp[i - 1][2] + 2);
                dp[i][2] = min(dp[i - 1][1] + 2, dp[i - 1][2] + 1);
            }
            else if(a[i][0] == '.' && a[i][1] == '*'){
                dp[i][1] = min(dp[i - 1][0] + 1, min(dp[i - 1][1] + 2, dp[i - 1][2] + 2));
                dp[i][2] = min(dp[i - 1][0], min(dp[i - 1][1] + 2, dp[i - 1][2] + 1));
            }
            else if(a[i][0] == '*' && a[i][1] == '.'){
                dp[i][1] = min(dp[i - 1][0], min(dp[i - 1][1] + 1, dp[i - 1][2] + 2));
                dp[i][2] = min(dp[i - 1][0] + 1, min(dp[i - 1][1] + 2, dp[i - 1][2] + 2));
            }
            else{
                dp[i][1] = min(dp[i - 1][0] + 1, min(dp[i - 1][1], dp[i - 1][2]) + 2);
                dp[i][2] = min(dp[i - 1][0] + 1, min(dp[i - 1][1], dp[i - 1][2]) + 2);
            }
        }

        int pos = n;
        for (int i = n; i >= 1; i--){
            if(a[i][0] == '*' || a[i][1] == '*'){
                pos = i;
                break;
            }
        }
        int ans = min(dp[pos][1], dp[pos][2]);
        cout << ans << "\n";
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= 2; j++){
                dp[i][j] = inf;
            }
        }
    }
    return 0;
}