/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, q, a[maxn];

unordered_map<int, vector<int>> mv;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mv[a[i]].push_back(i + 1);
    }

    for (int i = 0; i < q; i++){
        int q, pos;
        cin >> q >> pos;
        if(mv.find(q)==mv.end() || mv[q].size() < pos){
            cout << -1 << endl;
        }
        else{
            cout << mv[q][pos - 1] << endl;
        }
    }
        return 0;
}