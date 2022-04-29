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
const int maxn = 200 + 10;

int n, m, begx, begy, vis[maxn][maxn];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
char a[maxn][maxn];

struct item{
    int x, y, val;
};

bool check(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
            if (a[i][j] == 'K')
                begx = i, begy = j;
        }
    }

    int ans = -1;
    queue<item> q;
    q.push({begx, begy, 0}), vis[begx][begy] = 1;
    while(!q.empty()){
        auto now = q.front();
        
        if(a[now.x][now.y] == 'H'){
            ans = now.val;
            break;
        }
        
        for (int k = 0; k < 8; k++){
            int nx = now.x + dx[k], ny = now.y + dy[k];
            if(check(nx, ny) && !vis[nx][ny] && a[nx][ny] != '*'){
                q.push({nx, ny, now.val + 1}), vis[nx][ny] = 1;
            }
        }
        q.pop();
    }

    cout << ans << endl;
    return 0;
}