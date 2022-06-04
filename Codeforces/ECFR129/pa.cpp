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

const int maxn = 50 + 10;
int t, n, m, a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int maxia = 0, maxib = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            maxia = max(maxia, a[i]);
        }
        cin >> m;
        for (int i = 1; i <= m; i++){
            cin >> b[i];
            maxib = max(maxib, b[i]);
        }

        cout << (maxia >= maxib ? "Alice\n" : "Bob\n");
        cout << (maxib >= maxia ? "Bob\n" : "Alice\n");
    }
    return 0;
}