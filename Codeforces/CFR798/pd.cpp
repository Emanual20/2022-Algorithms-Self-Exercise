/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-12
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

const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 10;
char a[maxn][maxn];
int t, n, m, res[4];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
                if(a[i][j] == 'B'){
                    res[0] = max(res[0], -i - j), res[1] = max(res[1], -i + j);
                    res[2] = max(res[2], i - j), res[3] = max(res[3], i + j);
                }
            }
        }

        int idx = -1, idy = -1, rem = inf;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int tmp = 0;
                tmp = max(i + j + res[0], i - j + res[1]);
                tmp = max(tmp, max(-i + j + res[2], -i - j + res[3]));
                if(tmp < rem){
                    idx = i, idy = j, rem = tmp;
                }
            }
        }
        cout << idx << " " << idy << "\n";

        for (int k = 0; k < 4; k++)
            res[k] = 0;
    }
    return 0;
}