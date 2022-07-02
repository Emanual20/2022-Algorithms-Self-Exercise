/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-12
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
vector<int> edges[maxn];
int t, n, sz[maxn], f[maxn], ans = 0;

void dfs(int now, int fm){
    int s1 = -1, s2 = -1;
    for(auto &nto : edges[now]){
        if(nto != fm){
            dfs(nto, now);
            sz[now] += sz[nto];
            if(s1 == -1)
                s1 = nto;
            else if(s2 == -1)
                s2 = nto;
        }
    }
    sz[now] += 1;

    if(s1 == -1)
        f[now] = 0;
    else if(s2 == -1)
        f[now] = max(sz[s1] - 1, 0);
    else
        f[now] = max(max(sz[s1] - 1 + f[s2], sz[s2] - 1 + f[s1]), 0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i < n; i++){
            int nfm, nto;
            cin >> nfm >> nto;
            edges[nfm].push_back(nto), edges[nto].push_back(nfm);
        }

        dfs(1, -1);
        cout << f[1] << "\n";

        for (int i = 1; i <= n; i++){
            edges[i].clear(), ans = 0, sz[i] = 0, f[i] = 0;
        }
    }
    return 0;
}