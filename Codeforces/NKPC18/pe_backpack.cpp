/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 50 + 10;
const int maxv = 2e3 + 10;
const int v = 2000;
int n, p, q, a[maxn];
int dp[maxv][maxv], ndp[maxv][maxv];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> p >> q;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        memset(ndp, 0, sizeof(ndp));
        for (int j = 0; j <= v; j++){
            for (int k = 0; k <= v; k++){
                if(dp[j][k]){
                    ndp[j][k] = 1;
                    int upper = a[i] / p;
                    for (int pp = 0; pp <= upper; pp++){
                        int qq = (a[i] - pp * p) / q;
                        ndp[min(j + pp, v)][min(k + qq, v)] = 1;
                    }
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    int ans = 0;
    for (int i = 1; i <= v; i++){
        for (int j = 1; j <= v; j++){
            if(dp[i][j])
                ans = max(ans, min(i, j));
        }
    }
    ans = ans * (p + q);
    cout << ans << endl;
    return 0;
}