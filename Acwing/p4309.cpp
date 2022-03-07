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
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
const long double eps = 1e-12;
struct node{
    int x, y;
};
vector<node> nodes;
vector<long double> ans;
int n, x_src, y_src;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x_src >> y_src;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        nodes.push_back({x, y});
    }

    int res = 0, cntx = 0, cnty = 0;
    ans.push_back(-inf);
    for (int i = 0; i < n; i++){
        int nx = nodes[i].x, ny = nodes[i].y;
        if(nx == x_src){
            cntx++;
        }
        else if(ny == y_src){
            cnty++;
        }
        else{
            long double tmp = (nodes[i].y - y_src) * (long double)1.0 / (nodes[i].x - x_src);
            ans.push_back(tmp);
        }
    }

    res += cntx > 0;
    res += cnty > 0;
    if(ans.size() == 1){
        cout << res << endl;
        return 0;
    }
    
    sort(ans.begin(), ans.end());
    for (int i = 1; i < ans.size(); i++){
        if(ans[i] - ans[i - 1] > eps){
            res++;
        }
    }

    cout << res << endl;
    return 0;
}