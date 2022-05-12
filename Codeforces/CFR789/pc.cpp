/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5000 + 10;
int t, n, p[maxn], pre[maxn], f[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> p[i];
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(p[i] > p[j])
                    f[i][j] = 1;
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                f[i][j] += f[i][j - 1];
            }
        }

        ll ans = 0;
        for (int b = 1; b <= n; b++){
            for (int c = b + 1; c <= n; c++){
                ans += (f[b][n] - f[b][c]) * 1ll * (f[c][b - 1]);
            }
        }
        cout << ans << "\n";

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                f[i][j] = 0;
            }
        }
    }
    return 0;
}