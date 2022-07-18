/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-17
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

const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int tot = 0, delta = 0, bond;

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
    int idx, root;
    Splay(){
        memset(tr, 0, sizeof(tr));
        idx = 0, root = 0;
    }
    
    void pushup(int x){
        tr[x].size = (tr[x].s[0] ? tr[tr[x].s[0]].size : 0) + 
                     (tr[x].s[1] ? tr[tr[x].s[1]].size : 0) + 
                     1;
        // TODO: do something
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

    int FindMiniGreater(int x){
        int u = root, res = -1;
        vector<int> cand;
        while(u){
            if(tr[u].val >= x)
                res = u, u = tr[u].s[0];
            else
                u = tr[u].s[1];
        }
        return res;
    }

    int get_k(int k){
        int u = root;
        while(1){
            // when we query node u, we should distribute its lazy tag to its sons.
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
        if(tr[u].s[0]) output(tr[u].s[0]);
        cout << tr[u].val << ":" << tr[u].size << " ";
        if(tr[u].s[1]) output(tr[u].s[1]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int q;
    cin >> q >> bond;
    Splay spl;
    spl.insert(-inf), spl.insert(inf);
    int L = 1, R = 2;
    while(q--){
        char ch;
        int x;
        cin >> ch >> x;
        if(ch == 'I'){
            if(x >= bond)
                spl.insert(x - delta), tot += 1;
        }
        else if(ch == 'A'){
            delta += x;
        }
        else if(ch == 'S'){
            delta -= x;
            int nr = spl.FindMiniGreater(bond - delta);
            spl.splay_basic(nr, 0), spl.splay_basic(L, nr);
            spl.tr[L].s[1] = 0;
            spl.pushup(L), spl.pushup(nr);
        }
        else if(ch == 'F'){
            if(spl.tr[spl.root].size - 2 < x){
                cout << -1 << "\n";
            }
            else{
                int nx = spl.get_k(spl.tr[spl.root].size - x);
                cout << spl.tr[nx].val + delta << "\n";
            }
        }
        // spl.output(spl.root);
        // cout << "\n";
    }
    cout << tot - (spl.tr[spl.root].size - 2) << "\n";
    
    return 0;
}