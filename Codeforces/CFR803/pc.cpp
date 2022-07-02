/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-28
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
int t, n, a[maxn];
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        mp.clear();
        int ntot = 0, ptot = 0, flag = 1;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            mp[a[i]] += 1;
        }

        flag = flag && (mp.size() <= 5);
        if(flag){
            vector<int> vec;
            for(auto &it : mp){
                int kk = it.first, vv = it.second;
                vv = max(vv, 3);
                for (int i = 1; i <= n; i++){
                    vec.push_back(kk);
                }
            }
            int nn = vec.size();
            for (int i = 0; i < nn; i++){
                for (int j = i + 1; j < nn; j++){
                    for (int k = j + 1; k < nn; k++){
                        int res = vec[i] + vec[j] + vec[k];
                        flag = flag && (mp.find(res) != mp.end());
                    }
                }
            }
        }

        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}