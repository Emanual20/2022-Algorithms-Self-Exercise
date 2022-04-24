/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-22
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> s;
        int lens = s.length();
        int resa = 0, resb = 0, flag = 1;
        for (int i = 0; i < lens; i++){
            if(s[i] == 'a'){
                if(resb != 0)
                    flag = flag && (resb > 1), resb = 0;
                resa++;
            }
            else{
                if(resa != 0)
                    flag = flag && (resa > 1), resa = 0;
                resb++;
            }
        }
        if(resa != 0)
            flag = flag && (resa > 1);
        if(resb != 0)
            flag = flag && (resb > 1);
        
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}