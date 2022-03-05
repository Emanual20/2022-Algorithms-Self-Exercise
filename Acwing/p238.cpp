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
const int maxn = 3e4 + 10;

int f[maxn], sz[maxn], dis[maxn], n, m;
void dsu_init(){
    for (int i = 1; i <= n; i++){
        f[i] = i, sz[i] = 1, dis[i] = 0;
    }
}

int find(int k){
    if(f[k] == k){
        return k;
    }

    int lowest_fa = find(f[k]);
    dis[k] = dis[k] + dis[f[k]];
    return f[k] = lowest_fa;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    n = 3e4;
    dsu_init();
    cin >> m;
    while(m--){
        char ch;
        int fm, to;
        cin >> ch >> fm >> to;
        if(ch == 'M'){
            int pfm = find(fm), pto = find(to);
            dis[pfm] = sz[pto], f[pfm] = pto, sz[pto] += sz[pfm];
        }
        else{
            int pfm = find(fm), pto = find(to);
            if(pfm != pto){
                cout << -1 << '\n';
            }
            else{
                cout << (dis[fm] == dis[to] ? 0 : abs(dis[fm] - dis[to]) - 1) << '\n';
            }
        }
    }
    return 0;
}