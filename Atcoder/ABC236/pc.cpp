/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-01-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
map<string, int> dict;
vector<string> words;
int vis[maxn];
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        words.push_back(s);
        dict[s] = i;
    }

    for (int i = 0; i < m; i++){
        string s;
        cin >> s;
        if(dict.find(s)!=dict.end()){
            vis[dict[s]] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(vis[i]){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }

    return 0;
}