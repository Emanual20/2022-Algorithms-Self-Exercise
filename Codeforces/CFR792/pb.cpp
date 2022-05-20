/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-19
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
ll a, b, c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        int maxi = max(a, max(b, c));
        if(maxi == a)
            cout << a << " " << a + b + c << " " << a + c << "\n";
        else if(maxi == b)
            cout << a + b << " " << b << " " << a + b + c << "\n";
        else
            cout << a + b + c << " " << b + c << " " << c << "\n";
    }
    return 0;
}