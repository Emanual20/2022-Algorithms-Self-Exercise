/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t, n, vis[maxn], root = -1;
vector<int> edges[maxn];
vector<int> seq;

vector<int> tmp_vec;
vector<vector<int>> ans;
void dfs(int now){
    tmp_vec.push_back(now), vis[now] = 1;
    if(edges[now].size() == 0){
        ans.push_back(tmp_vec);
    }
    for(auto &nto : edges[now]){
        if(!vis[nto]){
            dfs(nto);
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; i++){
            int x;
            cin >> x;

            if(i == x){
                root = x;
            }
            else{
                edges[x].push_back(i);
            }
        }

        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int now = q.front();
            seq.push_back(now);
            for(auto &nto : edges[now]){
                q.push(nto);
            }
            q.pop();
        }

        for (int i = 0; i < seq.size(); i++){
            auto now = seq[i];
            if(!vis[now]){
                tmp_vec.clear();
                dfs(now);
            }
        }

        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++){
            auto &tmp = ans[i];
            cout << tmp.size() << "\n";
            for(auto &it : tmp){
                cout << it << " ";
            }
            cout << "\n";
        }
        cout << "\n";

        ans.clear(), seq.clear();
        for (int i = 1; i <= n; i++){
            vis[i] = 0;
            edges[i].clear();
        }
        // clear vis
    }
    return 0;
}