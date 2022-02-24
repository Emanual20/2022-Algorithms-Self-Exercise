/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10, maxp = 100 + 10;
struct edge{
    int to, w;
};
vector<edge> edges[maxn];
int n, m, k;
int n1, n2, match[maxn], st[maxn], a[maxp][maxp];
vector<int> nodes1;

bool allocate_couple(int now){
    for(auto &iter : edges[now]){
        int nto = iter.to;
        if(!st[nto]){
            st[nto] = 1;
            if(!match[nto] || allocate_couple(match[nto])){
                match[now] = nto, match[nto] = now;
                return true;
            }
        }
    }
    return false;
}

int BipartiteMaxmatch(){
    memset(match, 0, sizeof(match));
    int ret = 0;
    for (auto &i : nodes1){
        if(!match[i]){
            memset(st, 0, sizeof(st));
            ret += allocate_couple(i);
        }
    }
    return ret;
}

bool check(int x, int y){
    return x > 0 && x <= n && y > 0 && y <= m && !a[x][y];
}

int trans(int x, int y){
    return (x - 1) * m + y;
}

void add_edge(int x1, int y1, int x2, int y2){
    if(check(x1, y1) && check(x2, y2)){
        edges[trans(x1, y1)].push_back({trans(x2, y2), 1});
    }
}

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++){
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(!a[i][j]){
                if((i + j)% 2 == 0){
                    n1++;
                    nodes1.push_back(trans(i, j));
                }
                else{
                    n2++;
                }
                for (int iter = 0; iter < 8; iter++){
                    add_edge(i, j, i + dx[iter], j + dy[iter]);
                }
            }
        }
    }

    int ans = BipartiteMaxmatch();
    cout << n * m - k - ans << endl;
    return 0;
}