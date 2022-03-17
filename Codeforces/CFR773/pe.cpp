/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
 
int n, q, a[maxn];
struct node{
    int sum, left, right;
} tree[4 * maxn];
 
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)
 
void Pushup(int k){
    tree[k].sum = min(tree[lson(k)].sum, tree[rson(k)].sum);
}
 
void build(int left, int right, int k = 1){
    tree[k].left = left, tree[k].right = right;
    if (left == right){
        tree[k].sum = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(left, mid, lson(k));
    build(mid + 1, right, rson(k));
    Pushup(k);
}
 
void Update_seg(int l, int r, int x, int y, int C, int k = 1){
    if (x <= l && r <= y){
        tree[k].sum = min(tree[k].sum, C);
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
    if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
    Pushup(k);
}
 
int Query_seg(int l, int r, int x, int y, int k = 1){
    int ret = inf;
    if (x <= l && r <= y){
        ret = tree[k].sum;
        return ret;
    }
    int mid = (l + r) >> 1;
    if (mid >= x) ret = min(ret, Query_seg(l, mid, x, y, lson(k)));
    if (mid < y) ret = min(ret, Query_seg(mid + 1, r, x, y, rson(k)));
    return ret;
}
 
set<int> st;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> q;
    for (int i = 1; i <= n + 1; i++){
        st.insert(i);
    }
 
    memset(a, 0x3f, sizeof(a));
    build(1, n + 1);
 
    int op;
    while(q--){
        cin >> op;
        if(op == 0){
            int l, r, x;
            cin >> l >> r >> x;
            if(x == 0){
                auto iter = st.lower_bound(l);
                while(*iter <= r){
                    auto tmp = st.upper_bound(*iter);
                    st.erase(iter);
                    iter = tmp;
                }
            }
            else if(x == 1){
                Update_seg(1, n + 1, l, l, min(r, Query_seg(1, n + 1, l, l)));
            }
        }
        else{
            int x;
            cin >> x;
            if(!st.count(x)){
                cout << "NO" << "\n";
            }
            else{
                int val_l = -1, val_r = -1;
                auto iter_l = st.lower_bound(x);
                if(iter_l == st.begin()) val_l = 0;
                else iter_l--, val_l = *iter_l;
                auto iter_r = st.upper_bound(x);
                val_r = *iter_r;
                
                int tmp = Query_seg(1, n + 1, val_l + 1, x);
                // cout<<tmp<<" "<<val_l<<" "<<val_r<<endl;
                bool chk = (tmp >= x && tmp <= val_r - 1);
                cout << (chk ? "YES" : "N/A") << "\n";
            }
        }
    }
    return 0;
}