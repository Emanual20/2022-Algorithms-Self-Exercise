/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
string s;
char ch;
int a[128];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        cin >> s >> ch;
        int len = s.length();
        for (int i = 0; i < len; i++){
            if(i % 2 == 0){
                a[s[i]]++;
            }
        }
        cout << (a[ch] > 0 ? "YES" : "NO") << endl;
    }
    return 0;
}