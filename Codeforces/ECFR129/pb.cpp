/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-23
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
int t, n, a[maxn], m, b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cin >> m;
        ll tot = 0;
        for (int j = 1; j <= m; j++){
            cin >> b[j];
            tot += b[j];
        }
        tot %= n;
        cout << a[tot] << "\n";
    }
    return 0;
}