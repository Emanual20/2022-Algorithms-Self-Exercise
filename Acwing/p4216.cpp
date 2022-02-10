/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/*
* Find all the loop in the graph
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int maxn = 3e5 + 10;
int n, m, vis[maxn], flag[maxn];
ll ans = 1;
vector<int> edges[maxn];
vector<int> ans_vec;
void dfs(int now, int fm, int step){
    vis[now] = 1, flag[now] = step;
    for(auto &to : edges[now]){
        if(to == fm) continue;
        if(!vis[to]){
            dfs(to, now, step + 1);
        }
        else if(vis[to] && step > flag[to]){
            ans_vec.push_back(step - flag[to] + 1);
            return;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int fm, to;
        cin >> fm >> to;
        edges[fm].push_back(to);
        edges[to].push_back(fm);
    }

    memset(vis, 0, sizeof(vis));
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i++){
        if(!vis[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    if(ans_vec.size() == 1){
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}