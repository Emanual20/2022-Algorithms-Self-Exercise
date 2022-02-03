/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n;
void solve(int x){
    int res = 1, now = x;
    while(now){
        now >>= 1;
        res <<= 1;
    }
    res >>= 1;
    // cout << res << endl;
    for (int i = res; i < x; i++){
        cout << i << " ";
    }
    // cout << "::";
    cout << x << " " << (x ^ res) << " ";
    for (int i = 0; i < res; i++){
        if((x ^ res) != i && x != i)
            cout << i << " ";
    }
    cout << endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        solve(n-1);
    }
}