/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
vector<string> vec;
int t;
string s;

int find_rank(string s){
    return lower_bound(vec.begin(), vec.end(), s) - vec.begin() + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for (char s = 'a'; s <= 'z'; s++){
        for (char t = 'a'; t <= 'z'; t++){
            if(s != t){
                string tmp = "";
                tmp = tmp + s + t;
                vec.push_back(tmp);
            }
        }
    }
    sort(vec.begin(), vec.end());

    cin >> t;
    while(t--){
        cin >> s;
        cout << find_rank(s) << "\n";
    }
    return 0;
}