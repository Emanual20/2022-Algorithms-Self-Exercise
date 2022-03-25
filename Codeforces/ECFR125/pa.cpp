/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 10;
int t, x, y;
int dis[maxn][maxn], vis[maxn][maxn];
struct point{
    int x, y;
};
queue<point> q;

int calc_dis(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void init(){
    memset(vis, 0, sizeof(vis));
    q.push({0, 0}), vis[0][0] = 1;
    while(!q.empty()){
        point now = q.front();
        int nx = now.x, ny = now.y;
        for (int i = 0; i <= 50; i++){
            for (int j = 0; j <= 50; j++){
                if(!vis[i][j]){
                    int tmp = calc_dis(now.x, now.y, i, j);
                    int sqtmp = floor(sqrt(tmp));
                    if(tmp == sqtmp * sqtmp){
                        vis[i][j] = 1, dis[i][j] = dis[nx][ny] + 1;
                        q.push({i, j});
                    }
                }
            }
        }
        q.pop();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> t;
    while(t--){
        cin >> x >> y;
        cout << dis[x][y] << endl;
    }
    return 0;
}