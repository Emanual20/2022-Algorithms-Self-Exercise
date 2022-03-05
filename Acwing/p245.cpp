/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-04
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

int a[maxn], n, q;
struct node{
    int sum, totmax, lmax, rmax;
    int left, right;
} tree[4 * maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

void Pushup(int k){
    tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
    tree[k].totmax = max(max(tree[lson(k)].totmax, tree[rson(k)].totmax), max(tree[lson(k)].rmax + max(0, tree[rson(k)].lmax), max(0, tree[lson(k)].rmax) + tree[rson(k)].lmax));
    tree[k].lmax = max(tree[lson(k)].lmax, tree[lson(k)].sum + tree[rson(k)].lmax);
    tree[k].rmax = max(tree[rson(k)].rmax, tree[rson(k)].sum + tree[lson(k)].rmax);
}

void build(int left, int right, int k = 1){
	tree[k].left = left, tree[k].right = right;
	if (left == right){
		tree[k].sum = tree[k].totmax = tree[k].lmax = tree[k].rmax = a[left];
		return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, lson(k));
	build(mid + 1, right, rson(k));
	Pushup(k);
}

void Update_seg(int l, int r, int x, int y, int C, int k = 1){
	if (x <= l && r <= y){
		tree[k].sum = tree[k].totmax = tree[k].lmax = tree[k].rmax = C;
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
	if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
	Pushup(k);
}

node Query_seg(int l, int r, int x, int y, int k = 1){
	node ret = {0, -inf, -inf, -inf, 0, 0};
	if (x <= l && r <= y){
		return tree[k];
	}
	int mid = (l + r) >> 1;
    node tmpl = {-inf}, tmpr = {-inf};
    if (mid >= x){
        tmpl = Query_seg(l, mid, x, y, lson(k));
        ret.sum += tmpl.sum;
        ret.lmax = max(ret.lmax, tmpl.lmax);
        ret.totmax = max(ret.totmax, tmpl.totmax);
    }
	if (mid < y){
        tmpr = Query_seg(mid + 1, r, x, y, rson(k));
        ret.sum += tmpr.sum;
        ret.rmax = max(ret.rmax, tmpr.rmax);
        ret.totmax = max(ret.totmax, tmpr.totmax);
    };
    if(tmpl.sum != -inf && tmpr.sum != -inf){
        ret.lmax = max(ret.lmax, tmpl.sum + tmpr.lmax);
        ret.rmax = max(ret.rmax, tmpr.sum + tmpl.rmax);
        ret.totmax = max(ret.totmax, max(max(0, tmpl.rmax) + tmpr.lmax, tmpl.rmax + max(0, tmpr.lmax)));
    }
	return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, n);
    while(q--){
        int type, x, y;
        cin >> type >> x >> y;
        if(type == 1){
            if(x > y) swap(x, y);
            node ans = Query_seg(1, n, x, y);
            cout << ans.totmax << "\n";
        }
        else if(type == 2){
            Update_seg(1, n, x, x, y);
        }
    }
    return 0;
}