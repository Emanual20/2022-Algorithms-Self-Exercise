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

const int maxn = 5e3 + 10;
int n, r, pre[maxn][maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> r;
    r = min(r, 5001);
    for (int i = 1; i <= n; i++){
        int nx, ny, nw;
        cin >> nx >> ny >> nw;
        nx += 1, ny += 1;
        pre[nx][ny] += nw;
    }

    for (int i = 1; i <= 5002; i++){
        for (int j = 1; j <= 5002; j++){
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int i = r; i <= 5002; i++){
        for (int j = r; j <= 5002; j++){
            int res = pre[i][j] - pre[i - r][j] - pre[i][j - r] + pre[i - r][j - r];
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}