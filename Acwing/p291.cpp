/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 12;
const int maxm = 1 << 12;
ll dp[maxn][maxm], st[maxm];
int n, m;
void init(int n, int m){
    memset(st, 0, sizeof(st));
    for (int i = 0; i < (1 << m); i++){
        int now = i, cnt = 0;
        for(int j = 0; j < m; j++){
            cnt += !(now & 1);
            if(now & 1){
                if(cnt % 2){
                    st[i] = 1;
                    break;
                }
                cnt = 0;
            }
            now >>= 1;
        }
        cnt % 2 ? st[i] = 1 : st[i] = st[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n>>m, n||m){
        init(n, m);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < (1 << m); i++){
            dp[0][i] = !st[i];
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < (1 << m); j++)
            {
                for (int k = 0; k < (1 << m); k++)
                {
                    if (!((j & k) || st[j | k]))
                    {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        
        cout << dp[n-1][0] << endl;
    }
}