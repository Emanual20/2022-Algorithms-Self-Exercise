/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-05-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
 
const int maxn = 6e5 + 10;
const int inf = 0x3f3f3f3f;
 
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)
 
struct seg_node{
    ll sum, mini;
    int left, right;
    ll lazy;
};
 
struct seg_tree{
public:
	seg_node tree[4 * maxn];
 
	void Pushup(int k){
		tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
        tree[k].mini = min(tree[lson(k)].mini, tree[rson(k)].mini);
    }
 
	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = tree[k].mini = 0;
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
        tree[lson(k)].mini += tree[k].lazy;
        tree[rson(k)].mini += tree[k].lazy;
        tree[k].lazy = 0;
	}
 
	void Update_seg(int l, int r, int x, int y, ll C, int k = 1){
		if (x <= l && r <= y){
			tree[k].sum += (r - l + 1) * C;
            tree[k].mini += C;
            tree[k].lazy += C;
			return;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}
 
	ll Query_seg(int l, int r, int x, int y, int k = 1){
		ll ret = inf;
		if (x <= l && r <= y){
			ret = tree[k].mini;
			return ret;
		}
		Pushdown(k);
		int mid = (l + r) >> 1;
		if (mid >= x) ret = min(ret, Query_seg(l, mid, x, y, lson(k)));
		if (mid < y) ret = min(ret, Query_seg(mid + 1, r, x, y, rson(k)));
		return ret;
	}
};
 
int n;
struct line{
    int x, y;
};
vector<line> lines;
vector<int> vec;
 
int get_rank(int tmp){
    return lower_bound(vec.begin(), vec.end(), tmp) - vec.begin() + 1;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++){
        int nx, ny;
        cin >> nx >> ny;
        lines.push_back({nx, ny});
        vec.push_back(nx), vec.push_back(ny), vec.push_back(nx - 1);
    }
 
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    int lenv = vec.size();
    seg_tree st;
    st.build(1, lenv);
 
    for (auto &it : lines){
        int nx = it.x, ny = it.y;
        nx = get_rank(nx), ny = get_rank(ny);
        st.Update_seg(1, lenv, nx, ny, 1);
    }
 
    for (int i = 0; i < n; i++){
        int nx = lines[i].x, ny = lines[i].y;
        nx = get_rank(nx), ny = get_rank(ny);
        st.Update_seg(1, lenv, nx, ny, -1);
        int tmpx = st.Query_seg(1, lenv, nx, ny);
        st.Update_seg(1, lenv, nx, ny, 1);
        if(tmpx >= 1){
            cout << i + 1 << endl;
            return 0;
        }
    }
 
    cout << -1 << endl;
    return 0;
}