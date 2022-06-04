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
int tot1 = 0;

int trans(int x){
    x += 1;
    if(x >= 1 && x <= n)
        return x;
    else
        return x -= n;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        tot1 = 0;
        cin >> n >> s;
        for(auto &it : s)
            if(it == '1')
                tot1 += 1;

        if(tot1 % 2 != 0 || tot1 == 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            int beg = 0, lens = s.length();
            for (int i = 0; i < lens; i++){
                if(i != lens - 1 && s[i] == '1' && s[i + 1] == '0'){
                    beg = i;
                    break;
                }
                else if(i == lens - 1 && s[lens - 1] == '1' && s[0] == '0'){
                    beg = i;
                    break;
                }
            }
            string ns = s.substr(beg, lens - beg) + s.substr(0, beg);
            int res = beg, ntot = 0;
            for (int i = 1; i < lens; i++){
                if(ns[i] == '0'){
                    if(ntot == 0){
                        cout << trans(beg) << " " << trans(i + beg) << "\n";
                        ntot += 1;
                    }
                    else{
                        cout << trans(i + beg - 1) << " " << trans(i + beg) << "\n";
                    }
                }
                else{
                    if(ntot == 0){
                        cout << trans(beg) << " " << trans(i + beg) << "\n";
                    }
                    else{
                        cout << trans(i + beg - 1) << " " << trans(i + beg) << "\n";
                        ntot = 0;
                    }
                }
            }
        }
    }
    return 0;
}