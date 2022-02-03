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
const int maxn = 1e6 + 10;
const int inf = 0x3f3f3f3f;
int a[maxn], n, k;
struct item{
    int index, val;
};
deque<item> inc_s, dec_s;
/*
* Monotonous queue is suitable for this case:
*   1. Find the biggest(or smallest) element for fixed length window of an array.
* Note that we have to use a deque to imitate the Monotonous queue instead of a normal queue.
*/
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if(!inc_s.empty() && inc_s.front().index == i - k){
            inc_s.pop_front();
        }
        while(!inc_s.empty() && inc_s.back().val > a[i]){
            inc_s.pop_back();
        }
        inc_s.push_back({i, a[i]});
        if(i >= k - 1){
            cout << inc_s.front().val << " ";
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++){
        if(dec_s.front().index == i - k){
            dec_s.pop_front();
        }
        while(!dec_s.empty() && dec_s.back().val < a[i]){
            dec_s.pop_back();
        }
        dec_s.push_back({i, a[i]});
        if(i >= k - 1){
            cout << dec_s.front().val << " ";
        }
    }
    cout << endl;
    return 0;
}