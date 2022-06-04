/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-28
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
        sort(a + 1, a + n + 1);
        int flag = 1;
        flag = flag && (n % 2 == 0);
        for (int i = 1; i <= n / 2; i++){
            flag = flag && (a[i] != a[i + n / 2]);
        }
        for (int i = 1; i < n / 2; i++){
            flag = flag && (a[i] != a[i + n / 2 + 1]);
        }
        flag = flag && (a[1] != a[n]);

        if(flag){
            cout << "YES\n";
            for (int i = 1; i <= n / 2; i++){
                cout << a[i] << " " << a[i + n / 2] << " ";
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}