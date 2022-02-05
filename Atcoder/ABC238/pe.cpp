/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, q, vis[maxn];
vector<int> edges[maxn];
queue<int> que;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 0; i < q; i++){
        int fm, to;
        cin >> fm >> to;
        edges[to].push_back(fm - 1);
        edges[fm - 1].push_back(to);
    }

    que.push(0);
    vis[0] = 1;
    while(!que.empty()){
        int now = que.front();
        for (int i = 0; i < edges[now].size(); i++){
            if(!vis[edges[now][i]]){
                vis[edges[now][i]] = 1;
                que.push(edges[now][i]);
            }
        }
        que.pop();
    }
    if(vis[n]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}