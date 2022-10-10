/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-07-30
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

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int left, right;
    multiset<int> st;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
        for (int i = left; i <= right; i++){
            tree[k].st.insert(a[i]);
        }
		if (left == right){
			return;
		}
        int mid = (left + right) >> 1;
		build(left, mid, lson(k));
		build(mid + 1, right, rson(k));
	}

	void Update_seg(int l, int r, int x, int y, int npos, int nvalue, int k = 1){
        auto it = tree[k].st.find(a[npos]);
        tree[k].st.erase(it);
        tree[k].st.insert(nvalue);
        if (x <= l && r <= y){
            return;
		}		
        int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, npos, nvalue, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, npos, nvalue, rson(k));
	}

	int Query_seg(int l, int r, int x, int y, int qvalue, int k = 1){
		int ret = -1;
		if (x <= l && r <= y){
            auto res = tree[k].st.lower_bound(qvalue);
            if(res == tree[k].st.begin())
                return -1;
            res--;
            return *res;
        }
		int mid = (l + r) >> 1;
		if (mid >= x) ret = max(ret, Query_seg(l, mid, x, y, qvalue, lson(k)));
		if (mid < y) ret = max(ret, Query_seg(mid + 1, r, x, y, qvalue, rson(k)));
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
            int npos, nx;
            cin >> npos >> nx;
            segt.Update_seg(1, n, npos, npos, npos, nx);
            a[npos] = nx;
        }
        else if(op == 2){
            int nl, nr, nx;
            cin >> nl >> nr >> nx;
            auto res = segt.Query_seg(1, n, nl, nr, nx);
            cout << res << "\n";
        }
    }
    return 0;
}