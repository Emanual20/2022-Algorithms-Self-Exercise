/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e4 + 10;
int n, m, d[maxn], ans[maxn];
vector<int> edges[maxn];
bitset<maxn> st[maxn];

void topology_sort(){
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if(!d[i]){
            q.push(i);
        }
        st[i][i - 1] = '1';
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            st[iter] |= st[now];
            d[iter]--;
            if(!d[iter]){
                q.push(iter);
            }
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
        edges[to].push_back(fm);
        d[fm]++;
    }

    topology_sort();

    for (int i = 1; i <= n; i++){
        cout << st[i].count() << '\n';
    }
    return 0;
}