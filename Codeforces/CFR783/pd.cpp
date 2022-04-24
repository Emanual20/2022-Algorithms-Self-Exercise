/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-04-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int inf = 0x3f3f3f3f;

int t, n;
int blank[maxn];
ll a[maxn], pre[maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int maxi, left, right;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void Pushup(int k){
		tree[k].maxi = max(tree[lson(k)].maxi, tree[rson(k)].maxi);
	}

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].maxi = blank[left];
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k));
		build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Update_seg(int l, int r, int x, int y, int C, int k = 1){
		if (x <= l && r <= y){
			tree[k].maxi = max(tree[k].maxi, C);
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	int Query_seg(int l, int r, int x, int y, int k = 1){
		int ret = -inf;
		if (x <= l && r <= y){
			ret = tree[k].maxi;
			return ret;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) ret = max(ret, Query_seg(l, mid, x, y, lson(k)));
		if (mid < y) ret = max(ret, Query_seg(mid + 1, r, x, y, rson(k)));
		return ret;
	}
};

int dp[maxn];
vector<ll> vec;
int value2off(ll tmp){
    return lower_bound(vec.begin(), vec.end(), tmp) - vec.begin() + 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    memset(blank, 0x80, sizeof(blank));

    cin >> t;
    while(t--){
        cin >> n;
        vec.clear();

        vec.push_back(0);
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
            vec.push_back(pre[i]);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        seg_tree st1, st2, st3;
        st1.build(1, n + 1), st2.build(1, n + 1), st3.build(1, n + 1);
        st1.Update_seg(1, n + 1, value2off(0), value2off(0), 0);
        st2.Update_seg(1, n + 1, value2off(0), value2off(0), 0);
        st3.Update_seg(1, n + 1, value2off(0), value2off(0), 0);

        for (int i = 1; i <= n; i++){
            int now_off = value2off(pre[i]);
            int tmp1 = -inf;
            if(now_off > 1 && now_off <= n + 1) tmp1 = st1.Query_seg(1, n + 1, 1, now_off - 1);
            int tmp2 = st2.Query_seg(1, n + 1, now_off, now_off);
            int tmp3 = -inf;
            if(now_off < n + 1 && now_off >= 1) tmp3 = st3.Query_seg(1, n + 1, now_off + 1, n + 1);

            dp[i] = max(tmp1 + i, max(tmp2, tmp3 - i));
            st1.Update_seg(1, n + 1, now_off, now_off, dp[i] - i);
            st2.Update_seg(1, n + 1, now_off, now_off, dp[i]);
            st3.Update_seg(1, n + 1, now_off, now_off, dp[i] + i);
        }
        cout << dp[n] << "\n";
    }
    return 0;
}