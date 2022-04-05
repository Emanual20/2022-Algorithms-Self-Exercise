/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e3 + 10;
int t, n, a[maxn][maxn], tot[maxn];
string s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(tot, 0, sizeof(tot));
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++){
            cin >> s;
            for (int j = 0; j < n; j++){
                a[i][j] = s[j] - '0';
                res += a[i][j];
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                tot[(i - j + n) % n] += a[i][j];
            }
        }

        int maxi = 0;
        for (int i = 0; i < n; i++){
            maxi = max(maxi, tot[i]);
        }
        int ans = res - maxi + (n - maxi);
        cout << ans << endl;
    }
    return 0;
}