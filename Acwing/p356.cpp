/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const ll intinf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f;
int n, m;
struct edge{
    int fm, to, w;
    bool used;
};
bool comp(edge e1, edge e2){
    if(e1.w == e2.w)
        return e1.fm < e2.fm;
    return e1.w < e2.w;
}
vector<edge> edges[maxn];
vector<edge> alledges_vec;

int f[maxn];

void InitDSU(){
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
}

int find(int x){
    if(f[x] == x)
        return x;
    return f[x] = find(f[x]);
}

void merge(int dst, int src){
    int ndst = find(dst), nsrc = find(src);
    f[nsrc] = ndst;
}

ll kruskal(){
    ll ret = 0, tot = 0;
    for (int i = 0; i < alledges_vec.size(); i++){
        int nfm = alledges_vec[i].fm, nto = alledges_vec[i].to, nw = alledges_vec[i].w;
        if(find(nfm) != find(nto)){
            alledges_vec[i].used = 1, tot++, ret += nw;
            merge(nfm, nto);
            if(tot == n - 1){
                break;
            }
        }
    }
    return ret;
}

const int maxd = 18;
int depth[maxn], fa[maxn][maxd + 1];
int maximum1[maxn][maxd + 1], maximum2[maxn][maxd + 1];

void InitDepthAndFa(int root){
    memset(fa, 0, sizeof(fa));
    memset(depth, 0x3f, sizeof(depth));
    depth[0] = 0, depth[root] = 1, fa[root][0] = 0;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto &iter : edges[now]){
            int nto = iter.to, nw = iter.w;
            if(depth[nto] > depth[now] + 1){
                depth[nto] = depth[now] + 1;
                fa[nto][0] = now, maximum1[nto][0] = nw, maximum2[nto][0] = -intinf;
                for (int i = 1; i <= maxd; i++){
                    fa[nto][i] = fa[fa[nto][i - 1]][i - 1];

                    int candidates[4] = {maximum1[nto][i - 1],
                                         maximum2[nto][i - 1],
                                         maximum1[fa[nto][i - 1]][i - 1],
                                         maximum2[fa[nto][i - 1]][i - 1]};
                    int nmaxi1 = -intinf + 1, nmaxi2 = -intinf;
                    for (int j = 0; j < 4; j++){
                        if(candidates[j] > nmaxi1){
                            nmaxi2 = nmaxi1, nmaxi1 = candidates[j];
                        }
                        else if(candidates[j] != nmaxi1 && candidates[j] > nmaxi2){
                            nmaxi2 = candidates[j];
                        }
                    }
                    maximum1[nto][i] = nmaxi1;
                    maximum2[nto][i] = nmaxi2;
                }
                q.push(nto);
            }
        }
    }
}

vector<int> Calc_LCA(int x, int y){
    vector<int> ret = vector<int>();
    if(depth[x] < depth[y])
        swap(x, y);
    for (int i = maxd - 1; i >= 0; i--){
        if(depth[fa[x][i]] >= depth[y]){
            ret.push_back(maximum1[x][i]), ret.push_back(maximum2[x][i]);
            x = fa[x][i];
        }
    }
    if(x == y)
        return ret;
    for (int i = maxd - 1; i >= 0; i--){
        if(fa[x][i] != fa[y][i]){
            ret.push_back(maximum1[x][i]), ret.push_back(maximum2[x][i]);
            ret.push_back(maximum1[y][i]), ret.push_back(maximum2[y][i]);
            x = fa[x][i], y = fa[y][i];
        }
    }
    if(fa[x][0] != fa[y][0]){
        cerr << "fxxk" << endl;
    }
    ret.push_back(maximum1[x][0]), ret.push_back(maximum1[y][0]);
    return ret;
}

ll TryDeleteEdge(int fm, int to, int w){
    vector<int> candidates = Calc_LCA(fm, to);

    int nmaxi1 = -intinf + 1, nmaxi2 = -intinf;
    for (int j = 0; j < candidates.size(); j++){
        if(candidates[j] > nmaxi1){
            nmaxi2 = nmaxi1, nmaxi1 = candidates[j];
        }
        else if(candidates[j] != nmaxi1 && candidates[j] > nmaxi2){
            nmaxi2 = candidates[j];
        }
    }

    if(nmaxi1 != w){
        return w - nmaxi1;
    }
    else if(nmaxi2 != -intinf){
        return w - nmaxi2;
    }
    else
        return intinf;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int fm, to, w;
        cin >> fm >> to >> w;
        alledges_vec.push_back({fm, to, w, 0});
    }

    ll wmst = 0;
    InitDSU();
    sort(alledges_vec.begin(), alledges_vec.end(), comp);
    wmst = kruskal();

    for(auto &iter : alledges_vec){
        if(iter.used){
            edges[iter.fm].push_back({iter.fm, iter.to, iter.w, iter.used});
            edges[iter.to].push_back({iter.to, iter.fm, iter.w, iter.used});
        }
    }

    InitDepthAndFa(1);

    ll ans = llinf;
    for(auto &iter : alledges_vec){
        int nfm = iter.fm, nto = iter.to, nw = iter.w, nused = iter.used;
        if(!nused){
            ans = min(ans, wmst + TryDeleteEdge(nfm, nto, nw));
        }
    }
    cout << ans << endl;
    return 0;
}