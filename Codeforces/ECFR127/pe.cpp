/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll MOD = 998244353;
int n;
string s;
 
vector<int> prepare(int root){
    vector<int> ret;
    queue<int> q;
    q.push(root), ret.push_back(root);
    while(!q.empty()){
        int now = q.front();
        int lson = now * 2, rson = now * 2 + 1;
        if(lson < (1 << n))
            q.push(lson), ret.push_back(lson);
        if(rson < (1 << n))
            q.push(rson), ret.push_back(rson);
        q.pop();
    }
    return ret;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> n >> s;
    ll ans = 1;
    int lens = s.length();
    for (int i = 0; i < lens; i++){
        int nindex = i + 1;
        if(nindex < (1 << (n - 1))){
            int lson = nindex * 2, rson = nindex * 2 + 1;
            vector<int> ltree, rtree;
            ltree = prepare(lson), rtree = prepare(rson);
            
            int flag = 1;
            for (int i = 0; i < ltree.size(); i++){
                flag = flag && (s[ltree[i] - 1] == s[rtree[i] - 1]);
            }
            if(!flag)
                ans = ans * 2 % MOD;
        }
    }
    cout << ans << endl;
    return 0;
}