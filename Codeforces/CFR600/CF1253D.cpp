/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 2e5 + 10;
int n, m;

struct line{
    int x, y;
};
vector<line> lines;

bool comp(line l1, line l2){
    if(l1.x != l2.x)
        return l1.x < l2.x;
    return l1.y < l2.y;
}

struct DSU{
public:
    int n, f[maxn], sz[maxn];
    // remember to call dsu_init
    void dsu_init(){
        for (int i = 1; i <= n; i++)
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
    for (int i = 1; i <= m; i++){
        int nfm, nto;
        cin >> nfm >> nto;
        if(nfm > nto)
            swap(nfm, nto);
        lines.push_back({nfm, nto});
    }

    DSU dsu;
    dsu.n = n, dsu.dsu_init();

    sort(lines.begin(), lines.end(), comp);
    int ans = 0, last = -1, index = 0;
    for (int i = 0; i < m; i++){
        int nx = lines[i].x, ny = lines[i].y;
        if(nx > last){
            int left = lines[index].x, right = last;
            for (int j = index; j < i; j++){
                dsu.merge(lines[j].x, lines[j].y);
            }
            set<int> st;
            for (int j = left; j <= right; j++){
                st.insert(dsu.find(j));
            }
            ans += (st.size() - 1);
            index = i;
        }
        last = max(last, ny);
    }
    cout << ans << endl;
    return 0;
}