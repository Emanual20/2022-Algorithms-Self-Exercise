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

ll MOD;
const int maxn = 1e5 + 10;
int a[maxn], n, q;
struct node{
    int left, right;
    ll sum;
    ll add_lazy;
    ll mul_lazy;
} tree[4 * maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

ll quickpow(ll base, ll index){
    ll ret = 1;
    while(index){
        if(index & 1) ret *= base, ret %= MOD;
        base *= base, base %= MOD;
        index >>= 1;
    }
    return ret;
}

void Pushup(int k){
    tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
    tree[k].sum %= MOD;
}

void build(int left, int right, int k = 1){
    tree[k].left = left, tree[k].right = right;
    tree[k].add_lazy = 0, tree[k].mul_lazy = 1;
    if (left == right){
        tree[k].sum = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(left, mid, lson(k));
    build(mid + 1, right, rson(k));
    Pushup(k);
}

void Pushdown(int k){
    if (tree[k].add_lazy == 0 && tree[k].mul_lazy == 1) return;
    tree[lson(k)].add_lazy = tree[lson(k)].add_lazy * tree[k].mul_lazy + tree[k].add_lazy;
    tree[lson(k)].mul_lazy *= tree[k].mul_lazy;
    tree[rson(k)].add_lazy = tree[rson(k)].add_lazy * tree[k].mul_lazy + tree[k].add_lazy;
    tree[rson(k)].mul_lazy *= tree[k].mul_lazy;
    tree[lson(k)].add_lazy %= MOD, tree[lson(k)].mul_lazy %= MOD;
    tree[rson(k)].add_lazy %= MOD, tree[rson(k)].mul_lazy %= MOD;

    tree[lson(k)].sum = tree[lson(k)].sum * tree[k].mul_lazy + tree[k].add_lazy * (tree[lson(k)].right - tree[lson(k)].left + 1);
    tree[rson(k)].sum = tree[rson(k)].sum * tree[k].mul_lazy + tree[k].add_lazy * (tree[rson(k)].right - tree[rson(k)].left + 1);
    tree[lson(k)].sum %= MOD, tree[rson(k)].sum %= MOD;
    tree[k].add_lazy = 0, tree[k].mul_lazy = 1;
}

void Update_seg_add(int l, int r, int x, int y, ll C, int k = 1){
    if (x <= l && r <= y){
        tree[k].sum += (r - l + 1) * C, tree[k].sum %= MOD;
        tree[k].add_lazy += C, tree[k].add_lazy %= MOD;
        return;
    }
    Pushdown(k);
    int mid = (l + r) >> 1;
    if(x <= mid) Update_seg_add(l, mid, x, y, C, lson(k));
    if(y > mid) Update_seg_add(mid + 1, r, x, y, C, rson(k));
    Pushup(k);
}

void Update_seg_mul(int l, int r, int x, int y, ll C, int k = 1){
    if (x <= l && r <= y){
        tree[k].sum *= C, tree[k].sum %= MOD;
        tree[k].mul_lazy *= C, tree[k].mul_lazy %= MOD;
        tree[k].add_lazy *= C, tree[k].add_lazy %= MOD;
        return;
    }
    Pushdown(k);
    int mid = (l + r) >> 1;
    if(x <= mid) Update_seg_mul(l, mid, x, y, C, lson(k));
    if(y > mid) Update_seg_mul(mid + 1, r, x, y, C, rson(k));
    Pushup(k);
}

ll Query_seg(int l, int r, int x, int y, int k = 1){
    ll ret = 0;
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> MOD;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    build(1, n);

    cin >> q;
    int t;
    while(q--){
        cin >> t;
        if(t == 1){
            ll l, r, c;
            cin >> l >> r >> c;
            Update_seg_mul(1, n, l, r, c);
        }
        else if(t == 2){
            ll l, r, c;
            cin >> l >> r >> c;
            Update_seg_add(1, n, l, r, c);
        }
        else{
            ll l, r;
            cin >> l >> r;
            ll ret = Query_seg(1, n, l, r) % MOD;
            cout << ret << '\n';
        }
    }
    return 0;
}