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
int n, q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while(q--){
        cin >> n;
        if(n == 1){
            cout << "No" << endl;
            continue;
        }
        int flag = 1;
        for (int i = 2; i <= sqrt(n); i++){
            flag = flag && (n % i);
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}