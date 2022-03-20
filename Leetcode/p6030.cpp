/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)
const int maxn = 2e5 + 10;

struct seg_node{
	int left, right;
    int sum, lsum, rsum;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];
    char s[maxn];

    void initarrays(string str){
        int lens = str.length();
        for(int i = 0; i < lens; i++){
            s[i + 1] = str[i]; 
        }
    }

    void Pushup(int k){
        tree[k].sum = max(tree[lson(k)].sum, tree[rson(k)].sum);
		if(s[tree[lson(k)].right] == s[tree[rson(k)].left])
            tree[k].sum = max(tree[k].sum, tree[lson(k)].rsum + tree[rson(k)].lsum);
        
        tree[k].lsum = tree[lson(k)].lsum;
        if(tree[lson(k)].lsum == tree[lson(k)].right - tree[lson(k)].left + 1 && s[tree[lson(k)].right] == s[tree[rson(k)].left])
            tree[k].lsum += tree[rson(k)].lsum;
        
        tree[k].rsum = tree[rson(k)].rsum;
        if(tree[rson(k)].rsum == tree[rson(k)].right - tree[rson(k)].left + 1 && s[tree[lson(k)].right] == s[tree[rson(k)].left])
            tree[k].rsum += tree[lson(k)].rsum;
    }

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = tree[k].lsum = tree[k].rsum = 1;
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k));
		build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Update_seg(int l, int r, int x, int y, char C, int k = 1){
		if (x <= l && r <= y){
            s[x] = C;
            return;
		}
		int mid = (l + r) >> 1;
		if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
		if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
		Pushup(k);
	}

	int Query_seg(int l, int r, int x, int y, int k = 1){
		int ret = 0;
		if (x <= l && r <= y){
			ret = tree[k].sum;
			return ret;
		}
		int mid = (l + r) >> 1;
		if (mid >= x) ret += Query_seg(l, mid, x, y, lson(k));
		if (mid < y) ret += Query_seg(mid + 1, r, x, y, rson(k));
		return ret;
	}
};

class Solution {
public:
    const int maxn = 2e5 + 10;
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int lens = s.length();
        vector<int> ret(queryCharacters.size());
        seg_tree st;
        st.initarrays(s);
        st.build(1, lens);
        
        for (int i = 0; i < queryCharacters.size(); i++){
            int nq_pos = queryIndices[i] + 1;
            char nq_ch = queryCharacters[i];
            st.Update_seg(1, lens, nq_pos, nq_pos, nq_ch);
            auto nq_ans = st.Query_seg(1, lens, 1, lens);
            ret[i] = nq_ans;
        }
        return ret;
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

}