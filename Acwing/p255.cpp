/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
const int maxm = 1e4 + 10;

struct node{
    int lson, rson;
    int left, right;
    int cnt;
} tree[maxn * 4 + maxn * 18];

vector<int> vec;

int GetDiscreteRank(int x){
    return lower_bound(vec.begin(), vec.end(), x) - vec.begin();
}

int n, a[maxn], Timestamp = 0, q;
int root[maxn];

void Pushup(int k){
    tree[k].cnt = tree[tree[k].lson].cnt + tree[tree[k].rson].cnt;
}

int build(int left, int right, int k){
    tree[k].left = left, tree[k].right = right;
    if(left == right){
        tree[k].cnt = 0;
        return k;
    }
    int mid = (left + right) >> 1;
    tree[k].lson = build(left, mid, ++Timestamp);
    tree[k].rson = build(mid + 1, right, ++Timestamp);
    Pushup(k); return k;
}

int Update_each(int l, int r, int x, int C, int pre){
    int now = ++Timestamp;
    tree[now] = tree[pre];
    if(x <= l && r <= x){
        tree[now].cnt += C;
        return now;
    }
    int mid = l + r >> 1;
    if(x <= mid)
        tree[now].lson = Update_each(l, mid, x, C, tree[now].lson);
    if(x > mid)
        tree[now].rson = Update_each(mid + 1, r, x, C, tree[now].rson);
    Pushup(now); return now;
}

int Query_seg(int l, int r, int x, int y, int k){
    int ret = 0;
    if(x <= l && r <= y){
        ret = tree[k].cnt;
        return ret;
    }
    int mid = (l + r) >> 1;
    if(mid >= x) ret += Query_seg(l, mid, x, y, tree[k].lson);
    if(mid < y) ret += Query_seg(mid + 1, r, x, y, tree[k].rson);
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        vec.push_back(a[i]);
    }
    vec.push_back(-inf);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    root[0] = build(1, n, ++Timestamp);
    for (int i = 1; i <= n; i++){
        root[i] = Update_each(1, n, GetDiscreteRank(a[i]), 1, root[i - 1]);
    }

    while(q--){
        int l, r, k;
        cin >> l >> r >> k;

        int bin_l = 1, bin_r = n;
        while(bin_l < bin_r){
            int bin_mid = (bin_l + bin_r) >> 1;
            int res = Query_seg(1, n, bin_l, bin_mid, root[r]) - Query_seg(1, n, bin_l, bin_mid, root[l - 1]);
            if(res >= k){
                bin_r = bin_mid;
            }
            else{
                k -= res;
                bin_l = bin_mid + 1;
            }
        }
        cout << vec[bin_r] << '\n';
    }
    return 0;
}