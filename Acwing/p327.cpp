/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll MOD = 1e8;
ll dp[13][4096];
int m, n, x, res[13], st[4096];

void init(){
    for (int i = 0; i < (1 << 12); i++){
        int tmp = i, last = -1, flag = 1;
        while(tmp)
            flag = flag && (last != 1 ? 1 : !(tmp & 1)), last = tmp & 1, tmp /= 2;
        st[i] = flag;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    init();
    res[0] = 0x3fffffff;
    for (int i = 1; i <= m; i++){
        int tmp = 0;
        for (int i = 1; i <= n; i++){
            cin >> x;
            tmp *= 2, tmp += x;
        }
        res[i] = tmp;
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m; i++){
        for (int j = 0; j < (i == 1 ? 1 : (1 << n)); j++){
            if(st[j])
            for (int k = 0; k < (1 << n); k++){
                if(st[k] && !(j & k) && (j & res[i - 1]) == j && (k & res[i]) == k){
                    dp[i][k] += dp[i - 1][j], dp[i][k] %= MOD;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++){
        ans = (ans + dp[m][i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}