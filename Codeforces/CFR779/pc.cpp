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
const int maxn = 1e5 + 10;
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
        int tot = 0, index = -1;
        for (int i = 1; i <= n; i++){
            if(a[i] == 1){
                tot++, index = i;
            }
        }
        if(tot != 1){
            cout << "NO\n";
            continue;
        }

        int x = 0, flag = 1;
        for (int i = index; i <= n; i++){
            x++;
            if(a[i] > x)
                flag = 0;
            x = a[i];
        }
        for (int i = 1; i < index; i++){
            x++;
            if(a[i] > x)
                flag = 0;
            x = a[i];
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}