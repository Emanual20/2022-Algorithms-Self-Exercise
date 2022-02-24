/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n1, n2, m, match[maxn], st[maxn];

bool allocate_couple(int now){
    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(!st[nto]){
            st[nto] = 1;
            if(!match[nto] || allocate_couple(match[nto])){
                match[now] = nto, match[nto] = now;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMaxmatch(){
    memset(match, 0, sizeof(match));
    int ret = 0;
    for (int i = 1; i <= n1; i++){
        if(!match[i]){
            memset(st, 0, sizeof(st));
            ret += allocate_couple(i);
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(cin >> n1 >> n2 >> m, n1){
        for (int i = 0; i < m; i++){
            int num, fm, to;
            cin >> num >> fm >> to;
            if(!fm || !to)
                continue;
            edges[fm].push_back({to + n1, 1}), edges[to + n1].push_back({fm, 1});
        }

        int ans = BipartiteMaxmatch();
        cout << ans << endl;
        for (int i = 1; i <= n1 + n2; i++){
            edges[i].clear();
        }
    }
    return 0;
}