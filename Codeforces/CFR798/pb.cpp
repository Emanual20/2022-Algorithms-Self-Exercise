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

const int maxn = 2e5 + 10;
int t, n, a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            b[i] = a[i];
        }

        if(n == 1){
            cout << -1 << "\n";
            continue;
        }

        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++){
            if(a[i] == b[i]){
                for (int j = i; j <= n; j++){
                    if(a[i] != b[j]){
                        swap(b[i], b[j]);
                        break;
                    }
                }
            }
        }
        if(a[n] == b[n]){
            swap(b[n - 1], b[n]);
        }

        for (int i = 1; i <= n; i++){
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}