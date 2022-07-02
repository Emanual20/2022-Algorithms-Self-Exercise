/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-06-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 2e5 + 10;
int t, n;
string strs, strt;

char istype(set<char> st){
    if(st.find('a') != st.end() && st.find('b') != st.end()){
        return 'b';
    }
    if(st.find('b') != st.end() && st.find('c') != st.end()){
        return 'c';
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> strs >> strt;
        set<char> st;
        int flag = 1;
        for (int i = 0; i < n; i++){
            if(strs[i] != strt[i]){
                st.insert(strs[i]), st.insert(strt[i]);
            }
            else
                continue;

            int pos = i;
            for (int j = i + 1; j < n; j++){
                pos = j;
                if(st.find(strs[j]) == st.end()){
                    pos = j - 1;
                    break;
                }
                if(st.find(strt[j]) == st.end()){
                    pos = j - 1;
                    break;
                }
            }

            char tp = istype(st);
            if(tp != -1){
                vector<int> vecs, vect;
                for (int j = i; j <= pos; j++){
                    if(strs[j] == tp){
                        vecs.push_back(j);
                    }
                    if(strt[j] == tp){
                        vect.push_back(j);
                    }
                }
                flag = flag && (vecs.size() == vect.size());
                for (int j = 0; j < vecs.size(); j++){
                    flag = flag && (vecs[j] >= vect[j]);
                }
            }

            i = pos + 1, st.clear();
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}