/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int t, n, m;
char a[maxn][maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++){
            for (int j = 0; j <= m + 1; j++){
                a[i][j] = 'o';
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }

        for (int i = n; i >= 1; i--){
            for (int j = 1; j <= m; j++){
                if(a[i][j] == '*'){
                    for (int k = i + 1; k <= n + 1; k++){
                        if(a[k][j] == '*' || a[k][j] == 'o'){
                            a[i][j] = '.', a[k - 1][j] = '*';
                            break;
                        }
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}