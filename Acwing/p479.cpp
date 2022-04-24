/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int n, w[maxn], dp[maxn][maxn], f[maxn][maxn];

void dfs(int left, int right){
    if(left > right)
        return;
    int root = f[left][right];
    cout << root << " ";
    dfs(left, root - 1), dfs(root + 1, right);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    for (int len = 1; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int left = i, right = i + len - 1;
            for (int k = left; k <= right; k++){
                int nlw = (k == left ? 1 : dp[left][k - 1]);
                int nrw = (k == right ? 1 : dp[k + 1][right]);
                int nscore = (left == right ? 0 : nlw * nrw) + w[k];
                if(nscore > dp[left][right]){
                    dp[left][right] = nscore, f[left][right] = k;
                }
            }
        }
    }

    cout << dp[1][n] << "\n";
    dfs(1, n);
    return 0;
}