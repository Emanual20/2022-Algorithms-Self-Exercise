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
const int maxn = 1e3 + 10;

int n, a[maxn][maxn], vis[maxn][maxn];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

struct item{
    int x, y;
};

item st[maxn][maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    
    for (int i = 0; i <= n + 1; i++){
        for(int j = 0; j <= n + 1; j++){
            a[i][j] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    queue<item> q;
    q.push({n, n}), vis[n][n] = 1;
    while(!q.empty()){
        auto now = q.front();
        if(now.x == 1 && now.y == 1)
            break;
        for (int k = 0; k < 4; k++){
            int nx = now.x + dx[k], ny = now.y + dy[k];
            if(!vis[nx][ny] && !a[nx][ny]){
                q.push({nx, ny}), vis[nx][ny] = 1, st[nx][ny] = {now.x, now.y};
            }
        }
        q.pop();
    }
    
    cout << "0 0\n";
    int nx = 1, ny = 1;
    while(nx != n || ny != n){
        int lastx = st[nx][ny].x, lasty = st[nx][ny].y;
        nx = lastx, ny = lasty;
        cout << lastx - 1 << " " << lasty - 1 << "\n";
    }
    return 0;
}