/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 300 + 10;
const ll inf = 0x3f3f3f3f3f3f;
int n, m, k;
ll dp[maxn][maxn];

struct line{
    int x, y, c;
};
vector<line> vec[maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	ll sum, left, right;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void Pushup(int k){
		tree[k].sum = min(tree[lson(k)].sum, tree[rson(k)].sum);
	}

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = inf;
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k));
		build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Update_seg(int l, int r, int x, int y, ll C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum = min(tree[k].sum, C);
			return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	ll Query_seg(int l, int r, int x, int y, int k = 1){
		ll ret = inf;
		if (x <= l && r <= y){
			ret = tree[k].sum;
			return ret;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) ret = min(ret, Query_seg(l, mid, x, y, lson(k)));
		if (mid < y) ret = min(ret, Query_seg(mid + 1, r, x, y, rson(k)));
		return ret;
	}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
        int nx, ny, nc;
        cin >> nx >> ny >> nc;
        vec[ny].push_back({nx, ny, nc});
    }

    seg_tree st[maxn];
    for (int i = 0; i <= n; i++){
        st[i].build(1, n + 1);
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    st[0].Update_seg(1, n + 1, 1, 1, dp[0][0]);

    for (int i = 1; i <= n; i++){
        for(int j = 0; j <= min(i, n); j++){
            dp[i][j] = dp[i - 1][j];
            if(i >= j)
                st[i - j].Update_seg(1, n + 1, j + 1, j + 1, dp[i][j]);
        }
        
        for(auto &iter : vec[i]){
            int nx = iter.x, ny = iter.y, nc = iter.c;
            int nlen = ny - nx + 1;
            for (int j = 0; j <= min(i, n); j++){
                if(j >= nlen){
                    ll idx = nx - 1 - j + nlen;
                    ll tmp = idx >= 0 ? st[idx].Query_seg(1, n + 1, j - nlen + 1, j + 1) : inf;
                    dp[i][j] = min(dp[i][j], tmp + nc);
                }

                if(i >= j){
                    st[i - j].Update_seg(1, n + 1, j + 1, j + 1, dp[i][j]);
                }
            }
        }
    }

    ll ans = inf;
    for (int i = k; i <= n; i++){
        for (int j = k; j <= n; j++){
            ans = min(ans, dp[i][j]);
        }
    }

    cout << (ans >= inf / 2 ? -1 : ans) << "\n";
    return 0;
}