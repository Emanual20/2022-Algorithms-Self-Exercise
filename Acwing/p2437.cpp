/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-08
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

const int maxn = 1e5 + 10;
int n, m;

struct Node{
    int s[2], fath;
    int size, val, flag;
    void init(int _val, int _fath){
        val = _val, fath = _fath, flag = 0;
    }
};

class Splay{
public:
    Node tr[maxn];
    int idx, root, n;
    Splay(int _n){
        memset(tr, 0, sizeof(tr));
        idx = 0, root = 0, n = _n;
    }
    
    void pushup(int x){
        tr[x].size = tr[tr[x].s[0]].size + tr[tr[x].s[1]].size + 1;
    }
    
    void pushdown(int x){
        // similar to pushdown of segment tree
        if(tr[x].flag){
            swap(tr[x].s[0], tr[x].s[1]);
            // reverse both sons
            tr[tr[x].s[0]].flag ^= 1, tr[tr[x].s[1]].flag ^= 1;
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
        if(!k) root = x;
    }

    void insert(int v){
        int u = root, nf = 0;
        while(u) nf = u, u = tr[u].s[v > tr[u].val];
        u = ++idx;
        if(nf) tr[nf].s[v > tr[nf].val] = u;
        tr[u].init(v, nf);
        splay_basic(u, 0);
    }

    int get_k(int k){
        int u = root;
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
        if(tr[u].val >= 1 && tr[u].val <= n)
            cout << tr[u].val << " ";
        if(tr[u].s[1]) output(tr[u].s[1]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    Splay spl(n);
    for (int i = 0; i <= n + 1; i++){
        spl.insert(i);
    }
    while(m--){
        int nl, nr;
        cin >> nl >> nr;
        nl = spl.get_k(nl), nr = spl.get_k(nr + 2);
        spl.splay_basic(nl, 0), spl.splay_basic(nr, nl);
        spl.tr[spl.tr[nr].s[0]].flag ^= 1;
    }
    spl.output(spl.root);
    return 0;
}