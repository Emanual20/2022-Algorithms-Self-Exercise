/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-13
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
int n, q;
ll a[maxn], pre[maxn];

bool comp(ll it1, ll it2){
    return it1 > it2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, comp);
    for (int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    while (q--){
        int nx, ny;
        cin >> nx >> ny;
        ll ans = pre[nx] - pre[nx - ny];
        cout << ans << "\n";
    }
    return 0;
}