/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int t, n, m, r, c, a[maxn][maxn], tot = 0;
char x;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        tot = 0;
        cin >> n >> m >> r >> c;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> x;
                a[i][j] = (x == 'W' ? 0 : 1);
                tot += a[i][j];
            }
        }

        if(tot == 0){
            cout << -1 << endl;
            continue;
        }

        if(a[r][c] == 1){
            cout << 0 << endl;
            continue;
        }
        else{
            int flag = 0;
            for (int i = 1; i <= m; i++){
                if(a[r][i] == 1){
                    flag = 1;
                }
            }
            for (int i = 1; i <= n; i++){
                if(a[i][c] == 1){
                    flag = 1;
                }
            }
            cout << (flag == 1 ? 1 : 2) << endl;
        }
    }
    return 0;
}