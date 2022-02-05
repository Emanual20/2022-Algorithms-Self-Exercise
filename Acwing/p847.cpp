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
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int n, m, vis[maxn], dis[maxn];
vector<int> edges[maxn];
struct item{
    int index;
    int dis;
};
queue<item> q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back(to);
    }

    memset(dis, 0x3f, sizeof(dis));
    q.push({1, 0});
    vis[1] = 1, dis[1] = 0;
    while(!q.empty()){
        item i_now = q.front();
        for(auto &to : edges[i_now.index]){
            if(!vis[to]){
                q.push({to, i_now.dis + 1});
                vis[to] = 1, dis[to] = i_now.dis + 1;
            }
        }
        q.pop();
    }

    cout << (dis[n] == inf ? -1 : dis[n]) << endl;
    return 0;
}