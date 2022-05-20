/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-17
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
map<string, int> mp;
int n, x;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int index = -1, maxi = -1;
    for (int i = 1; i <= n; i++){
        cin >> s >> x;
        if(mp.find(s) == mp.end()){
            mp[s] = x;
            if(x > maxi){
                index = i, maxi = x;
            }
        }
    }
    cout << index << endl;
    return 0;
}