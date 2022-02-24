/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-22
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
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin >> s;
        int kr = 0, kg = 0, kb = 0;
        for (int i = 0; i < s.length(); i++){
            if(s[i] == 'r'){
                kr++;
            }
            else if(s[i] == 'g'){
                kg++;
            }
            else if(s[i] == 'b'){
                kb++;
            }
            else if(s[i] == 'R'){
                if(kr == 0){
                    cout << "NO" << endl;
                    break;
                }
                else
                    kr--;
            }
            else if(s[i] == 'G'){
                if(kg == 0){
                    cout << "NO" << endl;
                    break;
                }
                else
                    kg--;
            }
            else if(s[i] == 'B'){
                if(kb == 0){
                    cout << "NO" << endl;
                    break;
                }
                else
                    kb--;
            }

            if(i == s.length() - 1){
                cout << "YES" << endl;
            }
        }
    }
}