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
int dp[maxn][maxn], a[maxn][maxn], r, c;
int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
int dfs(int x, int y){
    if(dp[x][y])
        return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++){
        if(a[x][y] > a[x+dx[i]][y+dy[i]]){
            dp[x][y] = max(dp[x][y], 1 + dfs(x + dx[i], y + dy[i]));
        }
    }
    return dp[x][y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= r; i++){
        a[i][0] = a[i][c + 1] = inf;
    }
    for (int i = 0; i <= c; i++){
        a[0][i] = a[r + 1][i] = inf;
    }

    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            dfs(i, j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}