/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-31
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

const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;

int n, q, a[maxn];

struct Splay_Node{
    int s[2], fath;
    int size, val, flag;
    void init(int _val, int _fath){
        val = _val, fath = _fath, flag = 0;
    }
};

class Splay{
public:
    Splay_Node tr[maxn * 30];
    int idx, root;
    Splay(){
        memset(tr, 0, sizeof(tr));
        idx = 0, root = 0;
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

    int get_k(int nroot, int k){
        int u = nroot;
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

    int get_rank(int nroot, int v){
        int u = nroot, ret = 0;
        while(1){
            pushdown(u);
            if(v < tr[u].val)
                u = tr[u].s[0];
            else if(v == tr[u].val)
                return ret + tr[tr[u].s[0]].size;
            else
                u = tr[u].s[1], ret += tr[tr[u].s[0]].size;
        }
    }

    void output(int u){
        pushdown(u);
        if(tr[u].s[0]) output(tr[u].s[0]);
        cout << tr[u].val << " ";
        if(tr[u].s[1]) output(tr[u].s[1]);
    }
};

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int sum, left, right;
    int spl_root;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];
    Splay spl;

    seg_tree(){
        spl = Splay();
    }

    void Pushup(int k){
        ;
    }

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = a[left];
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k)), build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Update_seg(int l, int r, int x, int y, int C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum += (r - l + 1) * C;
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	int Query_segrank(int l, int r, int x, int y, int nvalue, int k = 1){
        // todo
		int ret = 0;
		if (x <= l && r <= y){
			// do something
            ret = spl.get_rank(tree[k].spl_root, nvalue);
            return ret;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) ret += Query_segrank(l, mid, x, y, nvalue, lson(k));
		if (mid < y) ret += Query_segrank(mid + 1, r, x, y, nvalue, rson(k));
		return ret;
	}

	int Query_segproc(int l, int r, int x, int y, int nvalue, int k = 1){
		int ret = -1;
		if (x <= l && r <= y){
			// do something
			return ret;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) ret = max(ret, Query_segproc(l, mid, x, y, nvalue, lson(k)));
		if (mid < y) ret = max(ret, Query_segproc(mid + 1, r, x, y, nvalue, rson(k)));
		return ret;
	}

	int Query_segsucc(int l, int r, int x, int y, int nvalue, int k = 1){
		int ret = inf;
		if (x <= l && r <= y){
			// do something
			return ret;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) ret = min(ret, Query_segsucc(l, mid, x, y, nvalue, lson(k)));
		if (mid < y) ret = min(ret, Query_segsucc(mid + 1, r, x, y, nvalue, rson(k)));
		return ret;
	}    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    seg_tree segt;
    segt.build(1, n);
    int op;
    while(q--){
        cin >> op;
        if(op == 1){
            // 1 l r x, check rank of integer 'x' in [L, R]
            int nl, nr, nx;
            cin >> nl >> nr >> nx;
            auto res = segt.Query_segrank(1, n, nl, nr, nx);
            cout << res + 1 << "\n";
        }
        else if(op == 2){
            // 2 l r k, query the value with rank 'k' in [L, R]
            int nl, nr, nk;
            cin >> nl >> nr >> nk;
            int binaryl = 0, binaryr = 1e8;
            while(binaryl < binaryr){
                int mid = binaryl + binaryr + 1 >> 1;
                if(segt.Query_segrank(1, n, nl, nr, mid) + 1 <= nk){
                    binaryl = mid;
                }
                else
                    binaryr = mid - 1;
            }
            cout << binaryr << "\n";
        }
        else if(op == 3){
            // 3 pos x, change the value of position x
        }
        else if(op == 4){
            // 4 l r x, query the proc of x in [L, R]
            int nl, nr, nx;
            cin >> nl >> nr >> nx;
            auto res = segt.Query_segproc(1, n, nl, nr, nx);
            cout << res << "\n";
        }
        else if(op == 5){
            // 5 l r x, query the succ of x in [L, R]
            int nl, nr, nx;
            cin >> nl >> nr >> nx;
            auto res = segt.Query_segsucc(1, n, nl, nr, nx);
            cout << res << "\n";
        }
    }
    return 0;
}