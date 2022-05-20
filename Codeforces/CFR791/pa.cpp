/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-14
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
int t;
ll n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        if(n < 4 || n % 2 == 1){
            cout << -1 << "\n";
            continue;
        }
        else{
            ll tot0 = n / 4;
            ll tot1 = 0;
            if(n % 6 == 0){
                tot1 = n / 6;
            }
            else if(n % 6 == 4){
                tot1 = (n - 4) / 6 + 1;
            }
            else{
                tot1 = (n - 8) / 6 + 2;
            }
            cout << tot1 << " " << tot0 << "\n";
        }
    }
    return 0;
}