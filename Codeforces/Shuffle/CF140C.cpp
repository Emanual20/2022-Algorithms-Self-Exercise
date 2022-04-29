/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-29
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
map<int, int> mp;

priority_queue<pii, vector<pii>> pq;
vector<vector<int>> ans;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int x;
    for (int i = 1; i <= n; i++){
        cin >> x;
        mp[x]++;
    }

    for (auto &it : mp){
        pq.push({it.second, it.first});
    }

    while(pq.size() >= 3){
        auto it1 = pq.top();
        pq.pop();
        auto it2 = pq.top();
        pq.pop();
        auto it3 = pq.top();
        pq.pop();
        vector<int> tmp(3, 0);
        tmp[0] = it1.second, tmp[1] = it2.second, tmp[2] = it3.second;
        sort(tmp.begin(), tmp.end(), greater<int>());
        ans.push_back(tmp);
        if(it1.first > 1)
            pq.push({it1.first - 1, it1.second});
        if(it2.first > 1)
            pq.push({it2.first - 1, it2.second});
        if(it3.first > 1)
            pq.push({it3.first - 1, it3.second});                    
    }

    cout << ans.size() << "\n";
    for(auto &it : ans){
        for(auto &item : it){
            cout << item << " ";
        }
        cout << "\n";
    }
    return 0;
}