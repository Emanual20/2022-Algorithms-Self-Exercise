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
const int maxn = 20 + 10;
ll dp[maxn][maxn];
ll sx, sy, ex, ey;
ll dx[9] = {-2, -2, -1, -1, 1, 1, 2, 2, 0}, dy[9] = {1, -1, 2, -2, 2, -2, 1, -1, 0};
bool available(ll x, ll y){
    for (int i = 0; i < 9; i++){
        if(x == sx + dx[i] && y == sy + dy[i]){
            return false;
        }
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> ex >> ey >> sx >> sy;
    dp[0][0] = 1;
    for (int i = 1; i <= ex; i++){
        available(i, 0) ? dp[i][0] = dp[i-1][0] : dp[i][0] = 0;
    }
    for (int i = 1; i <= ey; i++){
        available(0, i) ? dp[0][i] = dp[0][i-1] : dp[0][i] = 0;
    }

    for (int i = 1; i <= ex; i++)
    {
        for (int j = 1; j <= ey; j++)
        {
            available(i, j) ? dp[i][j] = dp[i - 1][j] + dp[i][j - 1] : dp[i][j] = 0;
        }
    }

    cout << dp[ex][ey] << endl;
    return 0;
}