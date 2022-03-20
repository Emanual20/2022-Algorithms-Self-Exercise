/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll n, s, sum, a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 1; i <= n; i++){
        ll l_bound = s - (sum - a[i]);
        ll r_bound = s - n + 1;
        ll tot = 0;
        if(l_bound > a[i]){
            tot = 0;
        }
        else{
            tot = min(r_bound, a[i]) - l_bound + 1;
        }
        cout << a[i] - tot << " ";
    }
    cout << endl;
    return 0;
}