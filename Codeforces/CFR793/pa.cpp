/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-22
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
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> s;
        int mid = (n - 1) / 2, tot = 0;
        char ch = s[mid];
        for (int i = mid; i < n; i++){
            if(s[i] == ch){
                tot += 1;
            }
            else
                break;
        }
        for (int i = mid; i >= 0; i--){
            if(s[i] == ch){
                tot += 1;
            }
            else
                break;            
        }
        cout << tot - 1 << "\n";
    }
    return 0;
}