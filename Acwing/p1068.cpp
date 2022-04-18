/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 400 + 10;
const int inf = 0x3f3f3f3f;
ll n, a[maxn], pre[maxn], dp[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[n + i] = a[i];
    }

    for (int i = 1; i <= 2 * n; i++){
        pre[i] = pre[i - 1] + a[i];
    }

    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= 2 * n; i++){
        dp[i][i] = 0;
    }
    for (int interval = 1; interval < n; interval++){
        for (int j = 1; j + interval < n * 2; j++){
            for (int k = 0; k < interval; k++){
                dp[j][j + interval] = min(dp[j][j + interval], 
                                          (dp[j][j + k] + dp[j + k + 1][j + interval]) + (pre[j + interval] - pre[j - 1]));
            }
        }
    }

    ll ans = inf;
    for (int i = 1; i <= n; i++){
        ans = min(ans, dp[i][i + n - 1]);
    }
    cout << ans << endl;
    
    memset(dp, 0, sizeof(dp));
    for (int interval = 1; interval < n; interval++){
        for (int j = 1; j + interval < n * 2; j++){
            for (int k = 0; k < interval; k++){
                dp[j][j + interval] = max(dp[j][j + interval], 
                                          (dp[j][j + k] + dp[j + k + 1][j + interval]) + (pre[j + interval] - pre[j - 1]));
            }
        }
    }

    ans = 0;
    for (int i = 1; i <= n; i++){
        ans = max(ans, dp[i][i + n - 1]);
    }
    cout << ans << endl;
    return 0;
}