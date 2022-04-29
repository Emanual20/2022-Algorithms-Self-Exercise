/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int n, m, a[maxn][maxn], vis[maxn][maxn];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct item{
    int x, y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            a[i][j] = 15;
        }
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(!vis[i][j]){
                queue<item> q;
                q.push({i, j}), vis[i][j] = 1;
                int tot = 1;
                while(!q.empty()){
                    auto now = q.front();
                    for (int k = 0; k < 4; k++){
                        if(a[i][j] & (1 << k))
                            continue;
                        int nx = now.x + dx[k], ny = now.y + dy[k];
                        if(!vis[nx][ny]){
                            q.push({nx, ny}), vis[nx][ny] = 1;
                            tot++;
                        }
                    }
                    q.pop();
                }
                ans = max(ans, tot);
            }
        }
    }

    cout << ans << endl;
    return 0;
}