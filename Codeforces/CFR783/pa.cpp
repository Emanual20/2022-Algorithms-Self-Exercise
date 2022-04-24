/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll t, n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n >= m)
            swap(n, m);
        if(n == 1){
            if(m <= 2)
                cout << m - 1 << endl;
            else
                cout << -1 << endl;
        }
        else{
            ll res = 2 * (n - 1), need = m - n;
            ll tmp0 = need / 2, tmp1 = need % 2;
            res += tmp0 * 4;
            res = res + (tmp1 == 1 ? 1 : 0);
            cout << res << endl;
        }
    }
    return 0;
}