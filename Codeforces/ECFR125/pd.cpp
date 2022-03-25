/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxc = 1e6 + 10;
const int maxn = 3e5 + 10;
ll n, C, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> C;
    vector<ll> f(C + 1);
    for (int i = 1; i <= n; i++){
        ll c, d, h;
        cin >> c >> d >> h;
        f[c] = max(f[c], d * h);
    }

    for (int i = 1; i <= C; i++){
        for (int j = i; j <= C; j += i){
            f[j] = max(f[j], f[i] * (j / i));
        }
    }

    for (int i = 1; i <= C; i++){
        f[i] = max(f[i], f[i - 1]);
    }

    cin >> m;
    while(m--){
        ll d, h;
        cin >> d >> h;
        auto iter = upper_bound(f.begin(), f.end(), d * h);
        if(iter == f.end()){
            cout << -1 << " ";
        }
        else cout << iter - f.begin() << " ";
    }
    cout << endl;
    return 0;
}