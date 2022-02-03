/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e2 + 10;
const int inf = 0x3f3f3f3f;
vector<int> a;
int pre[maxn], dp[maxn][maxn], n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1] + a[i];
    }

    memset(dp, inf, sizeof(dp));
    for (int i = 0; i < n; i++){
        dp[i][i] = 0;
    }
    for (int dx = 1; dx < n; dx++)
    {
        for (int i = 0; i + dx < n; i++)
        {
            for (int r = i; r < i + dx; r++)
            {
                dp[i][i + dx] = min(dp[i][i + dx],
                                    dp[i][r] + dp[r + 1][i + dx] + (pre[i + dx] - pre[r]) + (pre[r] - (i - 1 >= 0 ? pre[i - 1] : 0)));
            }
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}