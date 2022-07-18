/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-15
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
int t, n, x, a[maxn];
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        mp.clear();
        cin >> n >> x;
        for (int i = 1; i <= 2 * n; i++){
            cin >> a[i];
        }
        sort(a + 1, a + 2 * n + 1);
        int flag = 1;
        for (int i = 1; i <= n; i++){
            flag = flag && (a[i + n] - a[i] >= x);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}