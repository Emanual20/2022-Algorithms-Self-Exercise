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
const int maxn = 1024 + 10;
ll n, goal, dp[11][121][1024];

int st[1024];
int countbin1(int x){
    int ret = 0;
    while(x){
        x = x & (x - 1), ret++;
    }
    return ret;
}

void init(){
    memset(st, 0, sizeof(st));
    for (int i = 0; i < (1 << 10); i++){
        int tmp = i;
        int last = -1, res = 1;
        while(tmp)
            res = res && (last ? last != (tmp & 1) : 1), last = tmp & 1, tmp /= 2;
        st[i] = res;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init();
    cin >> n >> goal;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < (1 << n); j++){
            if(st[j])
            for (int k = 0; k < (1 << n); k++){
                if(st[k])
                if(!(j & k) && !((j << 1) & k) && !((j >> 1) & k)){
                    int tot = countbin1(k);
                    for (int p = 0; p <= (n * n); p++){
                        dp[i][p + tot][k] += dp[i - 1][p][j];
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << n); i++){
        ans += dp[n][goal][i];
    }
    cout << ans << endl;
    return 0;
}