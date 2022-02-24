/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int t, n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        cin >> n;
        for (int i = 1; i <= n; i++){
            a[i] = 1;
            cout << i << " ";
            for (int j = n; j >= 1; j--){
                if(!a[j]){
                    cout << j << " ";
                }
            }
            cout << "\n";
            a[i] = 0;
        }
    }
}