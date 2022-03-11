/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll ans[32], t, n;
void init(){
    ans[1] = 1;
    for (int i = 2; i <= 30; i++){
        ans[i] = 2 * ans[i - 1] + 1;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> t;
    while(t--){
        cin >> n;
        cout << ans[n] << '\n';
    }
    return 0;
}