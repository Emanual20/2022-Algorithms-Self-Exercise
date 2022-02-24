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
const int maxn = 2e3 + 10;
int n, m, a[maxn][maxn], w[maxn][maxn], st[maxn], d[maxn], ans = 0;

void solve(int offset){
    memset(st, 0, sizeof(st));
    int len;
    cin >> len;
    vector<int> vec;
    for (int i = 1; i <= len; i++){
        int x;
        cin >> x;
        vec.push_back(x), st[x] = 1;
    }
    vector<int> v1, v2;
    for (int i = vec[0]; i <= vec[len - 1]; i++){
        if(st[i]){
            v1.push_back(i);
        }
        else
            v2.push_back(i);
    }
    for (int i = 0; i < v1.size(); i++){
        a[n + offset][v1[i]] = 1, w[n + offset][v1[i]] = 0;
    }        
    for (int j = 0; j < v2.size(); j++){
        a[v2[j]][n + offset] = 1, w[v2[j]][n + offset] = 1;
    }
}

struct item{
    int index, v;
};

void topology_sort(){
    for (int i = 1; i <= n + m; i++){
        for (int j = 1; j <= n + m; j++){
            if(a[i][j]){
                d[j]++;
            }
        }
    }

    queue<item> q;
    for (int i = 1; i <= n + m; i++){
        if(!d[i]){
            q.push({i, 1});
        }
    }

    while(!q.empty()){
        item now = q.front();
        q.pop(), ans = max(ans, now.v);
        for (int i = 1; i <= n + m; i++){
            if(a[now.index][i]){
                d[i]--;
                if(d[i] == 0){
                    q.push({i, now.v + w[now.index][i]});
                }
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
        solve(i);
    }

    topology_sort();

    cout << ans << endl;
    return 0;
}