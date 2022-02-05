/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-02-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 60 + 10;
ll a, s, len, vis[maxn];
string stra, strs, res;
string lltostr(ll x){
    string ret;
    while(x){
        ret += (x & 1) + '0';
        x >>= 1;
    }
    // cout << "---" << x << " " << ret << endl;
    return ret;
}
bool solve(){
    for (int i = 0; i < stra.length(); i++){
        vis[i] = (stra[i] == '1');
    }
    int append = 0;
    for (int i = 0; i < res.length(); i++){
        res[i] = append + '0';
        append = (stra[i] == '1');
        if(append && i == res.length() - 1){
            res += '1';
        }
    }
    // cout << stra << " " << strs << " " << res << endl;
    if(res.length() > strs.length()){
        return false;
    }
    append = 0;
    for (int i = 0; i < strs.length(); i++){
        // cout << i << endl
        //      << res << endl
        //      << strs << endl;

        if(i >= res.length()){
            res += '0';
            res[i] += append;
        }
        else{
            res[i] += append;
        }
        append = 0;
        if(res[i] == '2' && append == 1){
            res[i] = '0', append = 1;
        }
        if(res[i] != strs[i] && vis[i]){
            return false;
        }
        if(res[i] == strs[i])
            continue;
        if (res[i] == '0' && strs[i] == '1'){
            res[i] = '1';
        }
        else{
            append = 1, res[i] = '0';
        }
    }
    return !append && strs.length() == res.length();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(cin >> a >> s){
        memset(vis, 0, sizeof(vis));
        stra.clear(), strs.clear(), res.clear();
        stra = lltostr(a);
        res = stra;
        strs = lltostr(s);
        len = max(stra.length(), strs.length());
        bool ans = solve();
        if(ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}