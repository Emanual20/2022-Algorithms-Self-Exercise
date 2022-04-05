/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a, b, c, d;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c >> d;
    int flag = 0, ans = 0;
    for (int i = 0; i <= 10000; i++){
        ll fcson = b - d + i * a;
        if (fcson / c * c == fcson && fcson / c >= 0){
            flag = 1, ans = i;
            break;
        }
    }
    if(flag){
        cout << b + ans * a << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}