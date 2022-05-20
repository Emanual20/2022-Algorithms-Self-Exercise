/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-19
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
int x, n, tot[maxn];
ll ans = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x;
        tot[x] += 1;
    }

    for (int i = 1; i <= 2e5; i++){
        for (int j = i; j <= 2e5; j += i){
            ans += 1ll * tot[i] * tot[j] * tot[j / i];
        }
    }

    cout << ans << endl;
    return 0;
}