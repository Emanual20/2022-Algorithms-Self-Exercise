/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-28
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
ifstream fin("./1.in");
ofstream fout("./1.txt");

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

int n, m, q, w[maxn];

struct DSU{
public:
    int f[maxn], sz[maxn];
    // remember to call dsu_init
    void init(){
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

struct Splay_Node{
    int s[2], fath;
    int size, val, flag;
    void init(int _val, int _fath){
        val = _val, fath = _fath, flag = 0;
    }
};

class Splay{
public:
    Splay_Node tr[maxn];
    int root[maxn], n;
    DSU dsu;
    Splay(int _n){
        memset(tr, 0, sizeof(tr));
        n = _n;
        for (int i = 1; i <= n; i++) root[i] = i, tr[i].val = w[i], tr[i].size = 1;
        dsu.init();
    }
    
    void pushup(int x){
        tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
        // TODO: do something
    }
    
    void pushdown(int x){
        // similar to pushdown of segment tree
        if(tr[x].flag){
            // TODO: do something
            tr[x].flag = 0;
        }
    }

    void rotate(int x){
        // unify left-rotate and right-rotate into one rotate function
        int y = tr[x].fath, z = tr[y].fath;
        int xisright = (x == tr[y].s[1]);
        int yisright = (y == tr[z].s[1]);
        // first from bottom to top
        tr[z].s[yisright] = x, tr[x].fath = z;
        tr[y].s[xisright] = tr[x].s[xisright ^ 1], tr[tr[x].s[xisright ^ 1]].fath = y;
        tr[x].s[xisright ^ 1] = y, tr[y].fath = x;
        // there is no need to pushup(z), cuz the state higher than z don't change
        pushup(y), pushup(x);
    }

    // rotate until node k is node x's **direct** father
    void splay_basic(int x, int k){
        while(tr[x].fath != k){
            int y = tr[x].fath, z = tr[y].fath;
            if(z != k)
                if((tr[z].s[1] == y) != (tr[y].s[1] == x)) rotate(x);
                else rotate(y);
            rotate(x);
        }
        if(!k) root[dsu.find(x)] = x;
    }

    void insert(int dst, int src){
        int v = tr[src].val;
        int u = root[dsu.find(dst)], nf = 0;
        while(u) nf = u, u = tr[u].s[v > tr[u].val];
        if(nf) tr[nf].s[v > tr[nf].val] = src;
        tr[src].init(v, nf), dsu.merge(dst, src);
        splay_basic(src, 0);
    }

    void merge(int dst, int src){
        if(dsu.find(dst) == dsu.find(src))
            return;
        if(tr[root[dsu.find(dst)]].size < tr[root[dsu.find(src)]].size)
            swap(dst, src);
        vector<int> vec; queue<int> q;
        vec.push_back(src), q.push(src);
        while(!q.empty()){
            int now = q.front();
            int lson = tr[now].s[0], rson = tr[now].s[1];
            if(lson)
                vec.push_back(lson), q.push(lson);
            if(rson)
                vec.push_back(rson), q.push(rson);
            q.pop();
        }
        for(auto &it : vec)
            this->insert(dst, it);
    }

    int get_k(int nroot, int k){
        int u = root[dsu.find(nroot)];
        if(tr[u].size < k)
            return -1;
        while(1){
            // when we query node u, we should distribute its lazy tag to its sons.
            pushdown(u);
            if(k <= tr[tr[u].s[0]].size)
                u = tr[u].s[0];
            else if(k == tr[tr[u].s[0]].size + 1)
                return u;
            else
                k -= (tr[tr[u].s[0]].size + 1), u = tr[u].s[1];
        }
        return -1;
    }

    void output(int u){
        pushdown(u);
        if(tr[u].s[0]) output(tr[u].s[0]);
        cout << tr[u].val << " ";
        if(tr[u].s[1]) output(tr[u].s[1]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    Splay spl(n);
    char ch; int nfm, nto;
    for (int i = 1; i <= m; i++){
        cin >> nfm >> nto;
        spl.merge(nfm, nto);
    }
    cin >> q;
    while(q--){
        cin >> ch >> nfm >> nto;
        if(ch == 'Q'){
            int nans = spl.get_k(nfm, nto);
            cout << nans << "\n";
        }
        else if(ch == 'B'){
            nfm = spl.dsu.find(nfm), nto = spl.dsu.find(nto);
            if(nfm != nto){
                spl.merge(nfm, nto);
            }
        }
    }
    return 0;
}