/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-03
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
const int inf = 0x3f3f3f3f;
ll t, n, a[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        ll mini = inf, tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            for (int j = 0; j <= 30; j++){
                if(a[i] & (1 << j)){
                    mini = min(mini, j * 1ll);
                    break;
                }
            }
            if(a[i] % 2 == 0){
                tot += 1;
            }
        }
        ll ans = (tot == n ? tot - 1 : tot) + mini;
        cout << ans << "\n";
    }
    return 0;
}