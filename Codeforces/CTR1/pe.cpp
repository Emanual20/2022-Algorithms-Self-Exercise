/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

vector<int> edges[maxn];
int n, t, ans[maxn];

void dfs(int now, int fm, int fmcolor){
    ans[now] = edges[now].size() * fmcolor;
    for(auto &iter : edges[now]){
        if(iter != fm){
            dfs(iter, now, -1 * fmcolor);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int fm, to;
        for (int i = 1; i < n; i++){
            cin >> fm >> to;
            edges[fm].push_back(to), edges[to].push_back(fm);
        }

        dfs(1, -1, 1);
        for (int i = 1; i <= n; i++){
            edges[i].clear();
        }

        for (int i = 1; i <= n; i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}