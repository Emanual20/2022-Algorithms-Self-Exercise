/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
int a[maxn], n;
struct item{
    int index, val;
};
stack<item> inc_s;
/*
* Monotonous stack is suitable for this case:
*   1. Find the nearest(either left or right) smaller(or greater) element for each index in n.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    inc_s.push({-1, -inf});
    for (int i = 0; i < n; i++){
        stack<item> tmp_s;
        while(!inc_s.empty()){
            item now = inc_s.top();
            if (now.val < a[i]){
                cout << (now.index >= 0 ? a[now.index] : -1) << " ";
                break;
            }
            inc_s.pop();
            tmp_s.push(now);
        }
        while(!tmp_s.empty()){
            inc_s.push(tmp_s.top());
            tmp_s.pop();
        }
        while(!inc_s.empty()){
            if(inc_s.top().val >= a[i]){
                inc_s.pop();
            }
            else
                break;
        }
        inc_s.push({i, a[i]});
    }
    cout << endl;
    return 0;
}