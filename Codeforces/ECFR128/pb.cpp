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

const int maxn = 5 + 10;
int t, n, m, a[maxn][maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                char x;
                cin >> x;
                a[i][j] = (x == 'E' ? 0 : 1);
            }
        }

        int lc = 10, rc = 10;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(a[i][j]){
                    lc = min(i - 1, lc);
                    rc = min(j - 1, rc);
                }
            }
        }

        int flag = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(a[i][j]){
                    int ln = i - 1, rn = j - 1;
                    flag = flag || (ln <= lc && rn <= rc);
                }
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}