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
const int maxn = 1e5 + 10;

struct myrelation{
    int l, r;
    string type;
};
vector<myrelation> relations;

map<int, int> mp;
int n, m, Timestamp = 0;

int f[maxn], dis[maxn];
void dsu_init(){
    for (int i = 1; i <= Timestamp; i++){
        f[i] = i, dis[i] = 0;
    }
}

int find(int k){
    if(f[k] == k) return k;
    int lowest_fat = find(f[k]);
    dis[k] = dis[k] + dis[f[k]];
    return f[k] = lowest_fat;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int l, r;
        string s;
        cin >> l >> r >> s;
        if(!mp.count(l-1)){
            mp[l - 1] = ++Timestamp;
        }
        if(!mp.count(r)){
            mp[r] = ++Timestamp;
        }
        relations.push_back({mp[l - 1], mp[r], s});
    }
    dsu_init();

    for (int i = 0; i < m; i++){
        int nl = relations[i].l, nr = relations[i].r, ntmp = relations[i].type == "even";
        if(ntmp){
            int pnl = find(nl), pnr = find(nr);
            if(pnl != pnr){
                f[pnl] = pnr;
                dis[pnl] = dis[nl] - dis[nr];
            }
            else if((dis[nl] - dis[nr]) % 2 != 0){
                cout << i << endl;
                return 0;
            }
        }
        else{
            int pnl = find(nl), pnr = find(nr);
            if(pnl != pnr){
                f[pnl] = pnr;
                dis[pnl] = dis[nl] - dis[nr] + 1;
            }
            else if((dis[nl] - dis[nr] - 1) % 2 != 0){
                cout << i << endl;
                return 0;
            }     
        }
    }
    cout << m << endl;
    return 0;
}