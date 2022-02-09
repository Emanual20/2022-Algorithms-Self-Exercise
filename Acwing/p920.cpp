/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e2 + 10;
const int inf = 0x3f3f3f3f;
vector<int> bus2stop[maxn];
string str;
int num_line, num_stop;
int n, m, edges[maxn][maxn], dist[maxn], vis[maxn];
void naive_dijkstra(int source){
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[source] = 0;
    for (int i = 1; i <= n; i++){
        int now_min = inf, now_index = -1;
        for (int j = 1; j <= n; j++){
            if(now_min > dist[j] && !vis[j]){
                now_min = dist[j];
                now_index = j;
            }
        }
        vis[now_index] = 1, dist[now_index] = now_min;
        for (int j = 1; j <= n; j++){
            if(!vis[j]){
                dist[j] = min(dist[j], dist[now_index] + edges[now_index][j]);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> num_line >> num_stop;
    getline(cin, str);
    for (int i = 1; i <= num_line; i++){
        getline(cin, str);
        int now = 0, len = str.length();
        for(int j = 0; j < len; j++){
            char ch = str[j];
            if(ch <= '9' && ch >= '0'){
                now *= 10;
                now += (ch - '0');
            }
            if(ch == ' ' || j == len - 1){
                bus2stop[i].push_back(now);
                now = 0;
            }
        }
    }

    memset(edges, 0x3f, sizeof(edges));
    for (int i = 1; i <= num_stop; i++){
        for (int _1 = 0; _1 < bus2stop[i].size(); _1++){
            for (int _2 = _1 + 1; _2 < bus2stop[i].size(); _2++){
                edges[bus2stop[i][_1]][bus2stop[i][_2]] = 1;
            }
        }
    }

    n = num_stop;
    int ans = inf;

    naive_dijkstra(1);
    ans = min(ans, dist[n]);

    if(ans >= inf / 2){
        cout << "NO" << endl;
    }
    else{
        cout << (ans - 1) << endl;
    }
    return 0;
}