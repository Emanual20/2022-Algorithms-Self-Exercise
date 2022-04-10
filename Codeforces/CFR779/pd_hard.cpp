/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, l, r, a[maxn], ori_tot[20], now_tot[20], ans[20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(ori_tot, 0, sizeof(ori_tot));
        memset(now_tot, 0, sizeof(now_tot));
        memset(ans, 0, sizeof(ans));

        cin >> l >> r;
        for (int i = 0; i <= r - l; i++){
            cin >> a[i];
        }

        for (int i = l; i <= r; i++){
            for (int j = 0; j < 17; j++){
                if(i & (1 << j))
                    ori_tot[j]++;
            }
        }

        for (int i = 0; i <= r - l; i++){
            for (int j = 0; j < 17; j++){
                if(a[i] & (1 << j))
                    now_tot[j]++;
            }
        }

        for (int j = 0; j < 17; j++){
            ans[j] = ori_tot[j] != now_tot[j];
        }

        int res = 0;
        for (int j = 17; j >= 0; j--){
            res *= 2;
            res += ans[j];
        }
        cout << res << "\n";
    }
    return 0;
}