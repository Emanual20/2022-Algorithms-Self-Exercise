/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct relation{
    int fm, to, t;
};
vector<relation> relations;

int t, n, m, Timestamp = 0;
int f[maxn], sz[maxn];
// remember to call dsu_init
void dsu_init(){
    for (int i = 1; i <= Timestamp; i++)
        f[i] = i;
}
int find(int k){
    if(f[k] == k)
        return k;
    return f[k] = find(f[k]);
}
void merge(int dst, int src){
    int ds = find(dst), sr = find(src);
    f[sr] = ds;
}

map<int, int> mp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        Timestamp = 0, relations.clear(), mp.clear();

        cin >> n;
        for (int i = 1; i <= n; i++){
            int fm, to, type;
            cin >> fm >> to >> type;
            if(!mp.count(fm)){
                mp[fm] = ++Timestamp;
            }
            if(!mp.count(to)){
                mp[to] = ++Timestamp;
            }
            relations.push_back({mp[fm], mp[to], type});
        }
        dsu_init();

        for (auto &iter : relations){
            int nfm = iter.fm, nto = iter.to, ntype = iter.t;
            if(ntype) merge(nfm, nto);
        }

        int flag = 1;
        for (auto &iter : relations){
            int nfm = iter.fm, nto = iter.to, ntype = iter.t;
            if(!ntype){
                flag = flag && (find(nfm) != find(nto));
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}