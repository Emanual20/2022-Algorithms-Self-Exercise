/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-19
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
int t, n, k, x;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        map<int, int> mp;
        multiset<int> mset;
        int tmp = k;
        for (int i = 1; i <= n; i++)
            cin >> x, mp[x]++, mset.insert(x);
        int mex = 0;
        for (mex = 0; mex <= n; mex++){
            if (mset.count(mex)) continue;
            if (k == 0) break;
            auto it = prev(mset.end());
            if (*it < mex) break;
            mset.erase(it);
            k--;
        }
        k = tmp;
        if (mex >= n){ 
            cout << 0 << endl; 
            continue;
        }

        vector<int> v;
        for (auto p : mp)
            if (p.first > mex)
                v.push_back(p.second);
        sort(v.begin(), v.end());
        
        int id = 0;
        while (id < v.size() && k >= v[id]) {
            k -= v[id];
            id++;
        }

        cout << v.size() - id << endl;
    }
    return 0;
}