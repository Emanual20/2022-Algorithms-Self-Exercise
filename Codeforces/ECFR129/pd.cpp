/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-23
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
ll n, x;

struct item{
    ll val, idx;
};

queue<item> q;
map<ll, int> mp;
string s;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> x;
    s = to_string(x);
    int flag = 0;
    for(auto &ch : s)
        flag = flag || (ch != '0' || ch != '1');
    if(!flag){
        cout << -1 << endl;
        return 0;
    }

    q.push({x, 0});
    while(!q.empty()){
        auto now = q.front();
        ll res = now.val;
        if(to_string(res).length() == n){
            cout << now.idx << endl;
            return 0;
        }

        if(mp.find(now.val) == mp.end()){
            set<ll> st;
            while(res)
                st.insert(res % 10), res /= 10;
            for(auto it : st)
                if(it > 1)
                    q.push({now.val * it, now.idx + 1});
        }

        q.pop();
    }
    return 0;
}