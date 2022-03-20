/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t, n, d[maxn], w[maxn], vis[maxn], nums[maxn];

struct edge{
    int to, index;
};
vector<edge> edges[maxn];

vector<int> begins;

void clearcontext(){
    for (int i = 1; i <= n; i++)
        edges[i].clear();
    memset(d, 0, sizeof(d));
    memset(vis, 0, sizeof(vis));
    begins.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i < n; i++){
            int fm, to;
            cin >> fm >> to;
            edges[fm].push_back({to, i}), edges[to].push_back({fm, i});
            d[fm]++, d[to]++;
        }

        int flag = 1;
        for (int i = 1; i <= n; i++){
            if(d[i] >= 3){
                flag = -1;
            }
            if(d[i] == 1){
                begins.push_back(i);
            }
        }

        if(flag == -1){
            cout << -1 << endl;
            clearcontext();
            continue;
        }
        else{
            queue<int> q;
            q.push(begins[0]), vis[begins[0]] = 1, nums[begins[0]] = 1;
            
            while(!q.empty()){
                int now = q.front();
                vis[now] = 1;
                for(auto &iter : edges[now]){
                    int nto = iter.to;
                    if(!vis[nto]){
                        w[iter.index] = (!nums[now] ? 2 : 3);
                        nums[nto] = !nums[now];
                        q.push(nto);
                    }
                }
                q.pop();
            }
            for (int i = 1; i < n; i++){
                cout << w[i] << " ";
            }
            cout << endl;
        }
        clearcontext();
    }
    return 0;
}   