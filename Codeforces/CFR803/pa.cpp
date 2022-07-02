/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-28
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

const int maxn = 2e5 + 10;
int t, n, a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }

        int idx = -1;
        for (int i = 1; i <= n; i++){
            int res = 0;
            for (int j = 1; j <= n; j++){
                if(i != j){
                    res ^= a[j];
                }
            }
            if(res == a[i]){
                idx = i;
                break;
            }
        }

        cout << a[idx] << "\n";
    }
    return 0;
}