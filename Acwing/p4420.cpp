/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 1e3 + 10;
const int maxp = 1e3 + 10;

int n, m;
char a[maxn][maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool valid(int x, int y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int trans(int x, int y){
    return (x - 1) * m + y + 1;
}

struct DSU{
public:
    int n, f[maxp], sz[maxp];
    // remember to call dsu_init
    void dsu_init(int maxq){
        for (int i = 1; i <= maxq; i++)
            f[i] = i, sz[i] = 1;
    }
    int find(int k){
        if(f[k] == k)
            return k;
        return f[k] = find(f[k]);
    }
    void merge(int dst, int src){
        int ds = find(dst), sr = find(src);
        f[sr] = ds;
        if(ds != sr) sz[ds] += sz[sr];
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }

    DSU dsu;
    dsu.dsu_init(trans(n, m));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(a[i][j] == '.'){
                for (int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    int rid = trans(i, j), nid = trans(nx, ny);
                    if(valid(nx, ny) && a[nx][ny] == '.' && dsu.find(rid) != dsu.find(nid)){
                        dsu.merge(rid, nid);
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(a[i][j] != '.'){
                set<int> st;
                int now = 1;
                for (int k = 0; k < 4; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    int rid = trans(i, j), nid = trans(nx, ny);
                    if(valid(nx, ny) && a[nx][ny] == '.' && st.find(dsu.find(nid)) == st.end()){
                        now += dsu.sz[nid], st.insert(dsu.find(nid));
                    }
                }
                now %= 10;
                a[i][j] = '0' + now;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cout << (char)a[i][j];
        }
        cout << endl;
    }

    return 0;
}