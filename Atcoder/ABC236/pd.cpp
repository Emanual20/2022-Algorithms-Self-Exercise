/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 17;
int ans = 0, n, a[maxn][maxn];
int vis[maxn];
void dfs(int step, int now){
    if(step == n){
        ans = max(ans, now);
        return;
    }
    int res = -1;
    for (int i = 0; i < 2 * n; i++){
        if(!vis[i]){
            res = i;
            break;
        }
    }
    for (int i = res + 1; i < 2 * n; i++){
        if(!vis[i]){
            vis[res] = 1, vis[i] = 1;
            // cout << "starting try" << res << " and " << i << " in " << step + 1 << " steps" << endl;
            dfs(step + 1, now ^ a[res][i]);
            // cout << "finishing try" << res << " and " << i << " in " << step + 1 << " steps" << endl;
            vis[res] = 0, vis[i] = 0;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < 2 * n; i++){
        for (int j = i + 1; j < 2 * n; j++){
            cin >> a[i][j];
        }
    }

    dfs(0, 0);
    cout << ans << endl;
    return 0;
}