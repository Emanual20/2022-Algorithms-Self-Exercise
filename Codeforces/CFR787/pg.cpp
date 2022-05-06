/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 250 + 10;
const int inf = 0x3f3f3f3f;
int n, m, a[maxn], pre[maxn];
int dp[maxn][maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    
    memset(dp, 0x3f, sizeof(dp));
    
    for (int i = 0; i <= m; i++){
        for (int j = i; j <= m; j++){
            dp[0][i][j] = 0;
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= m; j++){
            for (int k = 0; k <= j; k++){
                for (int x = k; x <= m; x++){
                // [k]:a_{i} >= [x]:a_{i-1}
                    dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - k][x] + abs(j - pre[i]));
                }
            }
        }
    }

    int ans = inf;
    for (int i = 0; i <= m; i++){
        ans = min(ans, dp[n][m][i]);
    }
    cout << ans << "\n";
    return 0;
}