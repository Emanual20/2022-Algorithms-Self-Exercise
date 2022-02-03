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
const int maxn = 1e3 + 10;
const int inf = 0x3f3f3f3f;
string a, b;
int dp[maxn][maxn], n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> a >> b;
    for (int i = 1; i <= a.length(); i++)
    {
        for (int j = 1; j <= b.length(); j++)
        {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i-1][j-1] + (a[i-1] == b[j-1]));
        }
    }

    cout << dp[a.length()][b.length()] << endl;
    return 0;
}