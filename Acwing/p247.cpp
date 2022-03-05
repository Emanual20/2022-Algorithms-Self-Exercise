/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-03-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4 + 10;

int n;
struct node{
    int left, right, cnt;
    double len;
} tree[4 * maxn];

#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#define father(x) ((x) >> 1)


map<double, int> mpy;
double a[maxn], mpi[maxn];
int Timestamp_y = 0;
struct line{
    double lreal, rreal;
    int lindex, rindex;
    double x;
    int inorout; // 1 means in, -1 means out
};
vector<line> lines;
bool comp(line l1, line l2){
    if(l1.x == l2.x)
        return l1.inorout < l2.inorout;
    return l1.x < l2.x;
}

vector<double> vy;
bool compy(double vy1, double vy2){
    return vy1 < vy2;
}

void Pushup(int k){
    if(tree[k].cnt) tree[k].len = mpi[tree[k].right + 1] - mpi[tree[k].left];
    else if(tree[k].left != tree[k].right){
        tree[k].len = tree[lson(k)].len + tree[rson(k)].len;
    }
    else
        tree[k].len = 0;
}

void build(int left, int right, int k = 1){
	tree[k].left = left, tree[k].right = right;
	if (left == right){
        tree[k].cnt = tree[k].len = 0;
        return;
	}
	int mid = (left + right) >> 1;
	build(left, mid, lson(k));
	build(mid + 1, right, rson(k));
}

void Update_seg(int l, int r, int x, int y, int C, int k = 1){
	if (x <= l && r <= y){
		tree[k].cnt += k;
        Pushup(k);
        return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) Update_seg(l, mid, x, y, C, lson(k));
	if(y > mid) Update_seg(mid + 1, r, x, y, C, rson(k));
	Pushup(k);
}

double Query_seg(int l, int r, int x, int y, int k = 1){
	double ret = tree[k].len;
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    while(cin >> n, ++t, n){
        cout << "Test case #" << t << '\n';
        mpy.clear(), vy.clear(), lines.clear(), Timestamp_y = 0;
        memset(mpi, 0, sizeof(mpi));
        memset(tree, 0, sizeof(tree));

        for (int i = 1; i <= n; i++){
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            vy.push_back(y1), vy.push_back(y2);
            lines.push_back({y1, y2, -1, -1, x1, 1});
            lines.push_back({y1, y2, -1, -1, x2, -1});
        }

        sort(vy.begin(), vy.end(), compy);
        for (int i = 0; i < vy.size(); i++){
            if(!mpy.count(vy[i])){
                mpy[vy[i]] = ++Timestamp_y;
                mpi[Timestamp_y] = vy[i];
            }
        }
        for (int i = 0; i < lines.size(); i++){
            lines[i].lindex = mpy[lines[i].lreal], lines[i].rindex = mpy[lines[i].rreal];
        }
        build(1, Timestamp_y);
        sort(lines.begin(), lines.end(), comp);
        
        long double ans = 0;
        Update_seg(1, Timestamp_y, lines[0].lindex, lines[0].rindex - 1, lines[0].inorout);
        for (int i = 1; i < lines.size(); i++){
            cout << (lines[i].x - lines[i - 1].x) << " " << Query_seg(1, Timestamp_y, 1, Timestamp_y) << endl;
            ans += (lines[i].x - lines[i - 1].x) *
                   Query_seg(1, Timestamp_y, 1, Timestamp_y);
            Update_seg(1, Timestamp_y, lines[i].lindex, lines[i].rindex - 1, lines[i].inorout);
        }

        cout << "Total explored area: ";
        cout << fixed << setprecision(2) << ans << '\n';
    }
    return 0;
}