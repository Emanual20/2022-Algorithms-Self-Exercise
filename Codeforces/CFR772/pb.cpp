/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int tot = 0;
        for (int i = 2; i < n; i++){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                a[i + 1] = max(a[i], a[i + 2]), tot++;
            }
        }
        cout << tot << "\n";
        for (int i = 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}