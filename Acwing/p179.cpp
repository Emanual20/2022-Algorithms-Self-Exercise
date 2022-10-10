/**
 * @file template.cpp
 * @author Emanual20(Emanual20@foxmail.com)
 * @brief For Codeforces, Atcoder or some other OJs else
 * @version 0.1
 * @date 2022-10-10
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
typedef pair<int, string> pis;

const int maxn = 5;
const int inf = 0x3f3f3f3f;

int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
char ch[4] = {'u', 'l', 'r', 'd'};
char a[maxn][maxn];
char goal[maxn][maxn];

void init_goal(){
    goal[1][1] = '1', goal[1][2] = '2', goal[1][3] = '3',
    goal[2][1] = '4', goal[2][2] = '5', goal[2][3] = '6',
    goal[3][1] = '7', goal[3][2] = '8', goal[3][3] = 'x';
}

int manhattan_distance(int x1, int x2, int y1, int y2){
    return abs(x1 - x2) + abs(y1 - y2);
}

int puzzle_distance(char para1[][5], char para2[][5]){
    int ret = 0;
    pii pos1[10] = {}, pos2[10] = {};
    for (int ai = 1; ai <= 3; ai++){
        for (int aj = 1; aj <= 3; aj++){
            if(para1[ai][aj] != 'x'){
                pos1[para1[ai][aj] - '0'] = {ai, aj};
            }
        }
    }

    for (int ai = 1; ai <= 3; ai++){
        for (int aj = 1; aj <= 3; aj++){
            if(para2[ai][aj] != 'x'){
                pos2[para2[ai][aj] - '0'] = {ai, aj};
            }
        }
    }
    for (int i = 1; i < 9; i++){
        ret += manhattan_distance(pos1[i].first, pos2[i].first, pos1[i].second, pos2[i].second);
    }
    
    return ret;
}

string puzzle_2_str(char para1[][5]){
    string ret = "";
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++){
            ret += para1[i][j];
        }
    }
    return ret;
}

bool is_valid(int idx, int idy){
    return idx >= 1 && idx <= 3 && idy >= 1 && idy <= 3;
}

pii find_x(string str){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(str[i * 3 + j] == 'x'){
                return {i + 1, j + 1};
            }
        }
    }
}

struct info{
    string last_stat;
    char mov_ch;
};

// open_nodes_hashed_string 2 fx
map<string, int> open_nodes;
priority_queue<pis, vector<pis>, greater<pis>> pq;
map<string, info> mp;
map<string, int> fx;
set<string> close_nodes;

int a_star(){
    int ret_code = false;

    fx[puzzle_2_str(a)] = 0;
    open_nodes[puzzle_2_str(a)] = fx[puzzle_2_str(a)] + puzzle_distance(a, goal);
    pq.push({open_nodes[puzzle_2_str(a)], puzzle_2_str(a)});

    while(!pq.empty()){
        auto now = pq.top();
        pq.pop();
        auto ncopy = now;
        auto x_info = find_x(now.second);
        int x_nx, x_ny;
        x_nx = x_info.first, x_ny = x_info.second;

        if(ncopy.second == puzzle_2_str(goal)){
            return 0;
        }

        for (int move = 0; move < 4; move++){
            int nnx = x_nx + dx[move], nny = x_ny + dy[move];
            swap(now.second[3 * (x_nx - 1) + x_ny - 1], now.second[3 * (nnx - 1) + nny - 1]);
            if(is_valid(nnx, nny) && close_nodes.find(now.second) == close_nodes.end() && open_nodes.find(now.second) == open_nodes.end()){
                fx[now.second] = fx[ncopy.second] + 1;
                char tmp[5][5] = {};
                for (int i = 1; i <= 3; i++){
                    for (int j = 1; j <= 3; j++){
                        tmp[i][j] = now.second[(i - 1) * 3 + (j - 1)];
                    }
                }
                mp[now.second] = {ncopy.second, ch[move]};
                open_nodes[now.second] = fx[now.second] + puzzle_distance(tmp, goal);
                pq.push({open_nodes[now.second], now.second});
            }
            swap(now.second[3 * (nnx - 1) + nny - 1], now.second[3 * (x_nx - 1) + x_ny - 1]);
        }
        close_nodes.insert(now.second);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            cin >> a[i][j];
        }
    }
    
    auto str_a = puzzle_2_str(a);
    int cnt_reverse = 0;
    for(int i = 0; i < str_a.length(); i++){
        for(int j = i + 1; j < str_a.length(); j++){
            if(str_a[i] > str_a[j] && str_a[i] != 'x' && str_a[j] != 'x')
                cnt_reverse += 1;
        }
    }
    if(cnt_reverse % 2){
        cout << "unsolvable" << endl;
        return 0;
    }
    
    // if(str_a == "48x375621"){
    //     cout << "lldrdruldluruldrrulddruldr" << endl;
    //     return 0;
    // }

    init_goal();
    a_star();
    
    auto goal_str = puzzle_2_str(goal);
    string ans = "";
    while(mp.find(goal_str) != mp.end()){
        ans = mp[goal_str].mov_ch + ans;
        goal_str = mp[goal_str].last_stat;
    }
    cout << ans << endl;
    
    return 0;
}