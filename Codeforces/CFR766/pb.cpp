/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t, n, m, vis[maxn], tot[maxn];
struct point{
    int x, y;
    int ans;
};
queue<point> q;
int dis(int x1, int y1, int x2, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}
int trans(int x, int y){
    return x * m + y;
}
int check(int x, int y){
    return max(max(dis(x, y, 1, 1), dis(x, y, n, m)), max(dis(x, y, n, 1), dis(x, y, 1, m)));
}
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

int valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
        memset(tot, 0, sizeof(tot));

        cin >> n >> m;
        while(!q.empty()){q.pop();}

        int tmp = inf, idx = -1, idy = -1;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int res = check(i, j);
                tmp = min(tmp, res);
            }
        }

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if(check(i, j) == tmp){
                    q.push({i, j, check(i, j)});
                    vis[trans(i, j)] = 1;
                }
            }
        }

        while(!q.empty()){
            auto now = q.front();
            for (int eps = 0; eps < 4; eps++){
                int nx = now.x + dx[eps], ny = now.y + dy[eps];
                int tmp = check(nx, ny);
                if(valid(nx, ny) && tmp == now.ans + 1 && !vis[trans(nx, ny)]){
                    q.push({nx, ny, tmp});
                    vis[trans(nx, ny)] = 1;
                }
            }
            tot[now.ans]++;
            q.pop();
        }

        for (int i = 1; i <= n * m; i++){
            for (int j = 0; j < tot[i]; j++){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}