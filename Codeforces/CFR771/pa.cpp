/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500 + 10;
int n, t, a[maxn], b[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int l = n + 1, r = -1;
        for (int i = 1; i <= n; i++){
            if(a[i] != i){
                l = i;
                break;
            }
        }

        for (int i = l + 1; i <= n; i++){
            if(a[i] == l){
                r = i;
                break;
            }
        }

        if(l == n + 1){
            for (int i = 1; i <= n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
            continue;
        }

        for (int i = 1; i <= l - 1; i++){
            cout << a[i] << " ";
        }
        for (int i = r; i >= l; i--){
            cout << a[i] << " ";
        }
        for (int i = r + 1; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}