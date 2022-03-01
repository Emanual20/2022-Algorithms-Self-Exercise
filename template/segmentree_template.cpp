#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
struct node{
	int sum, left, right;
	int lazy;
}tree[4*maxn];

void Pushup(int k){
	tree[k].sum = tree[k << 1].sum + tree[k << 1 | 1].sum;
	return;
}

void build(int k,int left, int right){
	tree[k].left = left;
	tree[k].right = right;
	if (left == right){
		tree[k].sum = a[left];
		return;
	}
	int mid = (left + right) >> 1;
	build(k << 1, left, mid);
	build(k << 1 | 1, mid + 1, right);

	Pushup(k);
}

void Pushdown(int k){
	if (tree[k].lazy == 0) return;

	tree[k << 1].lazy += tree[k].lazy;
	tree[k << 1 | 1].lazy += tree[k].lazy;
	tree[k << 1].sum += tree[k].lazy*(tree[k << 1].right - tree[k << 1].left + 1);
	tree[k << 1 | 1].sum += tree[k].lazy*(tree[k << 1 | 1].right - tree[k << 1 | 1].left + 1);
	tree[k].lazy = 0;
}

void Update_seg(int l, int r, int x, int y, int k, int C){
	if (x <= l && r <= y){
		tree[k].sum += (r - l + 1)*C;
		tree[k].lazy += C;
		return;
	}

	Pushdown(k);
	int mid = (l + r) >> 1;
	if(x<=mid) Update_seg(l, mid, x, y, k << 1, C);
	if(y>mid) Update_seg(mid + 1, r, x, y, k << 1 | 1, C);
	Pushup(k);
}

int Query_seg(int l, int r, int x, int y, int k){
	int sum = 0;
	if (x <= l && r <= y){
		sum = tree[k].sum;
		return sum;
	}

	Pushdown(k);

	int mid = (l + r) >> 1;
	if (mid >= x) sum += Query_seg(l, mid, x, y, k<<1);
	if (mid < y) sum += Query_seg(mid + 1, r, x, y, k << 1 | 1);
	return sum;
}