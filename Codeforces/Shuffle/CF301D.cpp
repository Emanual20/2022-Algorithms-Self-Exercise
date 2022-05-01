/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int n, q, pos[maxn], ans[maxn];

struct query{
    int l, index;
};
vector<query> queries[maxn];
vector<int> upds[maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int sum, left, right;
	int lazy;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void Pushup(int k){
		tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
	}

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = 0;
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k));
		build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Pushdown(int k){
		if (tree[k].lazy == 0) return;
		tree[lson(k)].lazy += tree[k].lazy, tree[rson(k)].lazy += tree[k].lazy;
		tree[lson(k)].sum += tree[k].lazy * (tree[lson(k)].right - tree[lson(k)].left + 1);
		tree[rson(k)].sum += tree[k].lazy * (tree[rson(k)].right - tree[rson(k)].left + 1);
		tree[k].lazy = 0;
	}

	void Update_seg(int l, int r, int x, int y, int C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum += (r - l + 1) * C;
			tree[k].lazy += C;
			return;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	int Query_seg(int l, int r, int x, int y, int k = 1){
		int ret = 0;
		if (x <= l && r <= y){
			ret = tree[k].sum;
			return ret;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if (mid >= x) ret += Query_seg(l, mid, x, y, lson(k));
		if (mid < y) ret += Query_seg(mid + 1, r, x, y, rson(k));
		return ret;
	}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pos[x] = i;
    }

    for (int i = 1; i <= q; i++){
        int nl, nr;
        cin >> nl >> nr;
        queries[nr].push_back({nl, i});
    }

    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j += i){
            int nl = pos[i], nr = pos[j];
            if(nl > nr)
                swap(nl, nr);
            upds[nr].push_back(nl);
        }
    }

    seg_tree st;
    st.build(1, n);
    for (int i = 1; i <= n; i++){
        for (auto &it : upds[i])
            st.Update_seg(1, n, it, it, 1);
        for (auto &it : queries[i]){
            int nl = it.l, nindex = it.index;
            ans[nindex] = st.Query_seg(1, n, nl, i);
        }
    }

    for (int i = 1; i <= q; i++){
        cout << ans[i] << "\n";
    }
    return 0;
}