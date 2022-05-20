/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-18
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
int n, m, vis[maxn];
vector<int> edges[maxn];

void dfs(int now, int fm){
    vis[now] = 1;
    for(auto &nto : edges[now]){
        if(!vis[nto]){
            cout << now << " " << nto << "\n";
            dfs(nto, now);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int nfm, nto;
        cin >> nfm >> nto;
        edges[nfm].push_back(nto), edges[nto].push_back(nfm);
    }

    memset(vis, 0, sizeof(vis));
    dfs(1, -1);
    cout << "\n";
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    q.push(1), vis[1] = 1;
    while(!q.empty()){
        auto now = q.front();
        for(auto &nto : edges[now]){
            if(!vis[nto]){
                cout << now << " " << nto << "\n";
                q.push(nto), vis[nto] = 1;
            }
        }
        q.pop();
    }
    return 0;
}