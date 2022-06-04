/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-21
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

const int maxn = 1e6 + 10;
int n;
ll ans = 0;

struct edge{
    int to, w;
};
vector<edge> edges[maxn];

void dfs(int now, int fm, int resw){
    map<int, int> mp;
    for(auto &it : edges[now]){
        int nto = it.to, nw = it.w;
        if(nto != fm){
            dfs(nto, now, nw);
            mp[nw] += 1;
        }
    }
    
    if(mp.find(resw) != mp.end())
        mp[resw] -= 1;

    for(auto &nit : mp){
        int nf = nit.first, ns = nit.second;
        ans += 1ll * (ns + 1) / 2 * nf;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++){
        int nfm, nto, nw;
        cin >> nfm >> nto >> nw;
        edges[nfm].push_back({nto, nw}), edges[nto].push_back({nfm, nw});
    }

    dfs(1, -1, 0);
    cout << ans << endl;
    return 0;
}

/*
11
1 2 2
2 3 1
3 4 1
3 5 1
4 7 1
4 6 1
5 8 1
5 9 1
5 10 2
10 11 2
*/

/*
7
1 2 1
2 4 3
2 5 4
1 3 2
3 6 5
3 7 6
*/