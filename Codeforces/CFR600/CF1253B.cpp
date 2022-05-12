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

const int maxn = 1e6 + 10;
set<int> st;
set<int> perm;
int n, a[maxn];
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    int tot = 0, last = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        
        if(a[i] > 0){
            if(perm.find(a[i]) != perm.end()){
                tot = -1;
                break;
            }
            st.insert(a[i]), perm.insert(a[i]);
        }
        else{
            if(st.find(-a[i]) == st.end()){
                tot = -1;
                break;
            }
            st.erase(-a[i]);
        }

        if(st.size() == 0){
            tot += 1;
            ans.push_back(i - last);
            st.clear(), perm.clear();
            last = i;
        }
        if(i == n && st.size() != 0){
            tot = -1;
        }
    }

    if(tot != -1){
        cout << tot << "\n";
        for(auto &it : ans)
            cout << it << " ";
    }
    else
        cout << -1 << "\n";
    return 0;
}