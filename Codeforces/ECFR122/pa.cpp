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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        if(n%7==0){
            cout << n << endl;
            continue;
        }
        n -= n % 10;
        for (int i = 0; i < 10; i++){
            if((n+i) % 7 ==0){
                cout << n + i << endl;
                break;
            }
        }
    }
}