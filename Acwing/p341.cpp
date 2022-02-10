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
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
vector<int> way_min[maxn];
vector<int> way_max[maxn];
int n, m, value[maxn], mins[maxn], maxs[maxn];
void dfs_min(int x, int m){
    if(m >= mins[x]) return;
    m = min(m, value[x]);
    mins[x] = m;
    for(int i = 0; i < way_min[x].size(); i++){
        dfs_min(way_min[x][i], m);
    }
}
void dfs_max(int x, int m){
    if(m <= maxs[x]) return;
    m = max(m, value[x]);
    maxs[x] = m;
    for(int i = 0; i < way_max[x].size(); i++){
        dfs_max(way_max[x][i], m);
    }
}
int main(){
    int ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> value[i];
        mins[i] = inf, maxs[i] = -inf;
    }
    for(int p = 1; p <= m; p++){
        int x, y, z;
        cin >> x >> y >> z;
        way_min[x].push_back(y);
        way_max[y].push_back(x);
        if(z == 2){
            way_min[y].push_back(x);
            way_max[x].push_back(y);
        }
    }
    
    dfs_min(1, value[1]);
    dfs_max(n, value[n]);
    
    for(int i = 1; i <= n; i ++){
        ans = max(ans, maxs[i] - mins[i]);
    }
    cout << ans << endl;
    return 0;
}