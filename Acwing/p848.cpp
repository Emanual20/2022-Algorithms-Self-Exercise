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
int n, m, incnt[maxn];
queue<int> q;
vector<int> edges[maxn];
vector<int> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int fm, to;
        cin >> fm >> to;
        incnt[to]++;
        edges[fm].push_back(to);
    }

    for (int i = 1; i <= n; i++){
        if(!incnt[i]){
            q.push(i);
        }
    }

    while(!q.empty()){
        int now = q.front();
        for(auto &to : edges[now]){
            incnt[to]--;
            if(!incnt[to]){
                q.push(to);
            }
        }
        ans.push_back(now);
        q.pop();
    }

    if(ans.size() == n){
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    else{
        cout << -1;
    }
    cout << endl;
    return 0;
}