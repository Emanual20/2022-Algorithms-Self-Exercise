/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e4 + 10;
const int inf = 0x3f3f3f3f;
int a[maxn];
struct node{
	int maxi, mini, left, right;
	int lazy;
}tree[4*maxn];

struct item{
    int mini, maxi;
};

void Pushup(int k){
	tree[k].maxi = max(tree[k << 1].maxi, tree[k << 1 | 1].maxi);
    tree[k].mini = min(tree[k << 1].mini, tree[k << 1 | 1].mini);
    return;
}

void build(int k,int left, int right){
	tree[k].left = left;
	tree[k].right = right;
	if (left == right){
		tree[k].maxi = tree[k].mini = a[left];
		return;
	}
	int mid = (left + right) >> 1;
	build(k << 1, left, mid);
	build(k << 1 | 1, mid + 1, right);

	Pushup(k);
}
item Query_seg(int l, int r, int x, int y, int k){
    item ret = {inf, -inf};
    if (x <= l && r <= y){
		ret.maxi = tree[k].maxi, ret.mini = tree[k].mini;
        return ret;
	}
	int mid = (l + r) >> 1;
	if (mid >= x){
        item i1 = Query_seg(l, mid, x, y, k<<1);
        ret.maxi = max(ret.maxi, i1.maxi), ret.mini = min(ret.mini, i1.mini);
    }
	if (mid < y){
        item i2 = Query_seg(mid + 1, r, x, y, k << 1 | 1);
        ret.maxi = max(ret.maxi, i2.maxi), ret.mini = min(ret.mini, i2.mini);
    }
	return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while(q--){
        int l, r;
        cin >> l >> r;
        item now = Query_seg(1, n, l, r, 1);
        cout << now.maxi - now.mini << endl;
    }
    return 0;
}