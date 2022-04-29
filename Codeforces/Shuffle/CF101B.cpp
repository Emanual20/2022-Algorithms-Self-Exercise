/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll MOD = 1e9 + 7;
int n, m, t;

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	ll sum, left, right;
    ll lazy;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void Pushup(int k){
		tree[k].sum = (tree[lson(k)].sum + tree[rson(k)].sum) % MOD;
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
		tree[lson(k)].lazy %= MOD, tree[rson(k)].lazy %= MOD;
        tree[lson(k)].sum += tree[k].lazy * (tree[lson(k)].right - tree[lson(k)].left + 1);
        tree[lson(k)].sum %= MOD;
        tree[rson(k)].sum += tree[k].lazy * (tree[rson(k)].right - tree[rson(k)].left + 1);
        tree[rson(k)].sum %= MOD;
        tree[k].lazy = 0;
	}

	void Update_seg(int l, int r, int x, int y, ll C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum += (r - l + 1) * C, tree[k].sum %= MOD;
			tree[k].lazy += C, tree[k].lazy %= MOD;
			return;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	ll Query_seg(int l, int r, int x, int y, int k = 1){
		ll ret = 0;
// 		cerr << l << " " << r << " " << x << " " << y << endl;
		if (x <= l && r <= y){
			ret = tree[k].sum;
			return ret;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if (mid >= x) ret += Query_seg(l, mid, x, y, lson(k));
		if (mid < y) ret += Query_seg(mid + 1, r, x, y, rson(k));
		return ret % MOD;
	}
};

vector<ll> vec;

int get_rank(ll x){
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
}

struct item{
    ll fm, to;
};

bool comp(item it1, item it2){
    if(it1.to == it2.to)
        return it1.fm < it2.fm;
    return it1.to < it2.to;
}

vector<item> buses;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int nfm, nto;
        cin >> nfm >> nto;
        buses.push_back({nfm, nto});
        vec.push_back(nfm), vec.push_back(nto);
    }
    sort(buses.begin(), buses.end(), comp);

    vec.push_back(0), vec.push_back(n);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    int nown = vec.size();
    seg_tree st;
    st.build(1, nown);
    st.Update_seg(1, nown, 1, 1, 1);
    for (auto &bus : buses){
        int nfm = bus.fm, nto = bus.to;
        nfm = get_rank(nfm), nto = get_rank(nto);
        ll nc = st.Query_seg(1, nown, nfm, nto - 1);
        st.Update_seg(1, nown, nto, nto, nc);
    }

    ll ans = st.Query_seg(1, nown, nown, nown);
    cout << ans << endl;
    return 0;
}