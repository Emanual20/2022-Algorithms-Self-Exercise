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
ll a[maxn], b[maxn], n, q;

ll ex_gcd(ll a, ll b) {
	return b == 0 ? a : ex_gcd(b, a % b);
}

struct node{
    ll gcd, sum;
    int left, right;
} tree[4 * maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

void Pushup(int k){
    tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
    tree[k].gcd = ex_gcd(tree[lson(k)].gcd, tree[rson(k)].gcd);
}

void build(int left, int right, int k = 1){
	tree[k].left = left, tree[k].right = right;
	if (left == right){
		tree[k].sum = tree[k].gcd = b[left];
		return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, lson(k));
	build(mid + 1, right, rson(k));
	Pushup(k);
}

void Update_seg(int l, int r, int x, int y, ll C, int k = 1){
	if (x <= l && r <= y){
		tree[k].sum += C, tree[k].gcd += C;
        return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
	if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
	Pushup(k);
}

int Query_seggcd(int l, int r, int x, int y, int k = 1){
	ll ret = -inf;
	if (x <= l && r <= y){
		ret = tree[k].gcd;
		return ret;
	}
	int mid = (l + r) >> 1;
	if (mid >= x) ret = Query_seggcd(l, mid, x, y, lson(k));
	if (mid < y && ret != -inf) ret = ex_gcd(ret, Query_seggcd(mid + 1, r, x, y, rson(k)));
    else if(mid < y && ret == -inf) ret = Query_seggcd(mid + 1, r, x, y, rson(k));
    return ret;
}

int Query_segsum(int l, int r, int x, int y, int k = 1){
	ll ret = 0;
	if (x <= l && r <= y){
		ret = tree[k].sum;
		return ret;
	}
	int mid = (l + r) >> 1;
	if (mid >= x) ret += Query_segsum(l, mid, x, y, lson(k));
	if (mid < y) ret += Query_segsum(mid + 1, r, x, y, rson(k));
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
    for (int i = 1; i <= n; i++){
        b[i + 1] = a[i] - a[i - 1];
    }
    build(1, n + 1);

    while(q--){
        ll left, right;
        cin >> left >> right;
        ll ans = Query_segsum(1, n + 1, 1, left + 1); 
        if(left < right) ans = ex_gcd(ans, Query_seggcd(1, n + 1, left + 2, right + 1));
        cout << abs(ans) << '\n';
    }
    return 0;
}