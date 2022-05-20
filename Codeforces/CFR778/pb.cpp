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
int t, n, a[128];
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        memset(a, 0, sizeof(a));
        n = s.length();
        for (int i = 0; i < n; i++){
            a[s[i]] += 1;
        }
        int pos = 0;
        for (int i = 0; i < n; i++){
            a[s[i]] -= 1;
            if(a[s[i]] <= 0){
                break;
            }
            pos += 1;
        }
        cout << s.substr(pos, n - pos) << "\n";
    }
    return 0;
}