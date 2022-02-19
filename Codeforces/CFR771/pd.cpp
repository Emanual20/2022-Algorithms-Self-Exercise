/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int n, m, a[maxn][maxn], good[maxn][maxn], tot = 0;
struct node{
    int x, y;
};
queue<node> q;
bool check(int x, int y){
    int color = 0, flag = 1;
    for (int dx = 0; dx <= 1; dx++){
        for (int dy = 0; dy <= 1; dy++){
            if(!color && a[x + dx][y + dy]){
                color = a[x + dx][y + dy];
            }
            if(a[x + dx][y + dy] && color != a[x + dx][y + dy]){
                flag = 0;
            }
        }
    }
    return good[x][y] && flag;
}
int retcolor(int x, int y){
    int ret = 0;
    for (int dx = 0; dx <= 1; dx++){
        for (int dy = 0; dy <= 1; dy++){
            tot += (a[x + dx][y + dy] != 0);
            if(ret == 0){
                ret = (a[x + dx][y + dy] ? a[x + dx][y + dy] : 0);
            }
        }
    }
    return (ret ? ret : n * m + 1);
}
void changecolor(int x, int y, int color){
    for (int dx = 0; dx <= 1; dx++){
        for (int dy = 0; dy <= 1; dy++){
            a[x + dx][y + dy] = color;
        }
    }
}
struct item{
    int x, y, color;
};
vector<item> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
 
    int beginx = 0, beginy = 0;
    for (int i = 1; i < n; i++){
        for (int j = 1; j < m; j++){
            good[i][j] = 1;
            if(check(i, j)){
                beginx = i, beginy = j;
                q.push({beginx, beginy});
            }
        }
    }
 
    if(q.empty()){
        cout << -1 << '\n';
        return 0;
    }
 
    while(!q.empty()){
        node now = q.front();
        q.pop();
        int nx = now.x, ny = now.y;
        if(!good[nx][ny])
            continue;
        int ncolor = retcolor(nx, ny);
        if(ncolor != n * m + 1){
            ans.push_back({nx, ny, ncolor});
        }
        changecolor(nx, ny, 0), good[nx][ny] = 0;
        for (int dx = -1; dx <= 1; dx++){
            for (int dy = -1; dy <= 1; dy++){
                if(good[nx + dx][ny + dy] && check(nx + dx, ny + dy)){
                    q.push({nx + dx, ny + dy});
                }
            }
        }
    }
    if(tot != n * m){
        cout << -1 << endl;
        return 0;
    }
    else{
        int iter = ans.size();
        cout << iter << '\n';
        for (int i = iter - 1; i >= 0; i--){
            cout << ans[i].x << " " << ans[i].y << " " << ans[i].color << '\n';
        }
    }
 
    return 0;
}