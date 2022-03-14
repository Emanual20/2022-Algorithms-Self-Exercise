/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int a[256];
string dic, s;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> dic >> s;
    for (int i = 0; i < 26; i++){
        a[dic[i]] = i + 1;
    }
    int res = 27, tot = 0;
    for (int i = 0; i < s.length(); i++){
        if(a[s[i]] > res)
            res = a[s[i]];
        else
            tot++, res = a[s[i]];
    }
    cout << tot << endl;
    return 0;
}