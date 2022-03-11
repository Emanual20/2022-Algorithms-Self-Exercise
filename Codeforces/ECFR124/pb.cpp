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
int t, n, ans[maxn];
void init(){
    ans[1] = 1;
    for (int i = 2; i <= 19; i++){
        ans[i] = ans[i - 1] * 3;
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
        if(n >= 20){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}