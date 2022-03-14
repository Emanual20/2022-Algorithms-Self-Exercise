/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 10;
int t, n, m;
string s;
vector<pii> vec;

bool ifintersect(pii p1, pii p2){
    return !(p1.second < p2.first || p2.second < p1.first || (p1.first == p2.first && p1.second == p2.second));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        vec.clear();
        int ans = 0;
        cin >> n >> m;

        for (int i = 0; i < n; i++){
            cin >> s;
            s += '0';
            vector<pii> nvec;
            int flag = 0, beg = -1;
            for (int j = 0; j <= m; j++){
                if(s[j] == '1' && !flag){
                    flag = 1, beg = j;
                }
                else if(s[j] == '0' && flag){
                    nvec.push_back(make_pair(beg, j - 1));
                    flag = 0, beg = -1;
                }
            }

            int res = 0;
            for(auto &iter_nvec : nvec){
                for(auto &iter_vec : vec){
                    res = res || ifintersect(iter_nvec, iter_vec);
                }
            }
            vec = nvec;
            ans = ans || res;
        }
        cout << (ans ? "NO" : "YES") << endl;
    }
    return 0;
}