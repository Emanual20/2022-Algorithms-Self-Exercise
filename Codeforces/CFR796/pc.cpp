/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-03
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
int t, n;
int tot[256];
string s[maxn];
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= 2 * n + 1; i++){
            cin >> s[i];
            for(auto &ch : s[i])
                tot[ch] += 1;
        }
        for (int i = 'a'; i <= 'z'; i++){
            if(tot[i] % 2 != 0){
                cout << (char)i;
            }
        }
        cout << "\n";
        memset(tot, 0, sizeof(tot));
    }
    return 0;
}