/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
string s;
int q;
char ch[128][3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> q;
    ch['A'][1] = 'B', ch['A'][2] = 'C';
    ch['B'][1] = 'C', ch['B'][2] = 'A';
    ch['C'][1] = 'A', ch['C'][2] = 'B';

    while(q--){
        ll t, k;
        cin >> t >> k;
        vector<int> res;
        while(t > 0 && k > 1){
            res.push_back(2 - (k % 2));
            k = (k + 1) / 2;
            t -= 1;
        }

        char beg;
        if(k == 1){
            t %= 3;
            beg = s[0];
            if(t == 1)
                beg = ch[beg][1];
            if(t == 2)
                beg = ch[ch[beg][1]][1];
        }
        else if(t == 0){
            beg = s[k - 1];
        }

        for (int i = res.size() - 1; i >= 0; i--){
            beg = ch[beg][res[i]];
        }
        cout << beg << '\n';
    }
    return 0;
}