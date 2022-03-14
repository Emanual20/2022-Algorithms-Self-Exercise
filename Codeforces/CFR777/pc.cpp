/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
int t, n, m, a[maxn][maxn];
string s;

bool check(int idx, int idy){
    if(!(idx >= 1 && idx <= n && idy >= 1 && idy <= m)) return false;
    if(a[idx][idy - 1] <= 0)
        return true;
    if(a[idx - 1][idy] <= 0)
        return true;
    return false;
}

struct point{
    int x, y;
};
queue<point> q;
struct item{
    int x1, y1, x2, y2;
};
vector<item> ans;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
int vis[maxn * maxn];
int trans(int x, int y){
    return x * (m + 1) + y;
}

void init_a(){
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= m + 1; j++){
            a[i][j] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        int tot = 0;
        cin >> n >> m;
        ans.clear();
        memset(a, 0, sizeof(a));

        init_a();
        for (int i = 1; i <= n; i++){
            cin >> s;
            for (int j = 0; j < m; j++){
                a[i][j + 1] = s[j] - '0';
                if(a[i][j + 1]) tot++;
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(a[i][j] && check(i, j)){
                    q.push({i, j}), vis[trans(i, j)] = 1;
                }
            }
        }

        while(!q.empty()){
            point now = q.front();
            if(a[now.x - 1][now.y] == 0){
                ans.push_back({now.x - 1, now.y, now.x, now.y});
            }
            else{
                ans.push_back({now.x, now.y - 1, now.x, now.y});
            }
            a[now.x][now.y] = 0;

            for (int i = 0; i < 4; i++){
                int nx = now.x + dx[i], ny = now.y + dy[i];
                if(a[nx][ny] && !vis[trans(nx, ny)] && check(nx, ny)){
                    q.push({nx, ny}), vis[trans(nx, ny)] = 1;
                }
            }
            q.pop(), vis[trans(now.x, now.y)] = 0, tot--;
        }
        
        if(tot != 0){
            cout << -1 << "\n";
        }
        else{
            cout << ans.size() << "\n";
            for (int i = ans.size() - 1; i >= 0; i--){
                cout << ans[i].x1 << " " << ans[i].y1 << " " << ans[i].x2 << " " << ans[i].y2 << "\n";
            }
        }
    }
    return 0;
}