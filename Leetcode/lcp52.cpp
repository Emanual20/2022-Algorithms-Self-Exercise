/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int maxn = 2e5 + 10;

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)

struct seg_node{
	int sum, color, left, right;
	int lazy;
};

struct seg_tree{
public:
	seg_node tree[4 * maxn];

	void Pushup(int k){
		tree[k].sum = tree[lson(k)].sum + tree[rson(k)].sum;
        if(tree[lson(k)].color == tree[rson(k)].color){
            tree[k].color = tree[lson(k)].color;
        }
        else tree[k].color = 0;
	}

	void build(int left, int right, int k = 1){
		tree[k].left = left, tree[k].right = right;
		if (left == right){
			tree[k].sum = 0, tree[k].color = 1, tree[k].lazy = 0;
			return;
		}
		int mid = (left + right) >> 1;
		build(left, mid, lson(k));
		build(mid + 1, right, rson(k));
		Pushup(k);
	}

	void Pushdown(int k){
		if (tree[k].lazy == 0) return;
		tree[lson(k)].lazy = tree[k].lazy, tree[rson(k)].lazy = tree[k].lazy;
		tree[lson(k)].color = tree[k].lazy;
		tree[rson(k)].color = tree[k].lazy;
        if(tree[k].lazy == 1) tree[lson(k)].sum = tree[rson(k)].sum = 0;
        else tree[lson(k)].sum = tree[lson(k)].right - tree[lson(k)].left + 1, 
             tree[rson(k)].sum = tree[rson(k)].right - tree[rson(k)].left + 1;
		tree[k].lazy = 0;
	}

	void Update_seg(int l, int r, int x, int y, int C, int k = 1){
		if (x <= l && r <= y){
			tree[k].color = C;
			tree[k].lazy = C;
            
            if(C == 2) tree[k].sum = tree[k].right - tree[k].left + 1;
            else if(C == 1) tree[k].sum = 0;            
			
            return;
		}
		Pushdown(k);
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
		Pushdown(k);
		int mid = (l + r) >> 1;
		if (mid >= x) ret += Query_seg(l, mid, x, y, lson(k));
		if (mid < y) ret += Query_seg(mid + 1, r, x, y, rson(k));
		return ret;
	}
};

class Solution {
public:
    vector<int> vec;
    void dfs(TreeNode* now){
        if(now->left) dfs(now->left);
        vec.push_back(now->val);
        if(now->right) dfs(now->right);
    }
    
    int get_rank(int x){
        return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;
    }
    
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
        vec = vector<int>();
        dfs(root);
        seg_tree st;
        st.build(1, vec.size());
        
        st.Update_seg(1, vec.size(), 1, vec.size(), 1);
        for(int i = 0; i < ops.size(); i++){
            int nop = ops[i][0], nleft = ops[i][1], nright = ops[i][2];
            nleft = get_rank(nleft), nright = get_rank(nright);
            
            st.Update_seg(1, vec.size(), nleft, nright, nop + 1);
        }
        
        int ret = st.Query_seg(1, vec.size(), 1, vec.size());
        return ret;
    }
};