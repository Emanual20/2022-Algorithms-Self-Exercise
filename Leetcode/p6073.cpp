const int maxn = 1e5 + 10;
class Solution {
public:
    string s;
    vector<int> edges[maxn];
    int dp[maxn], ans;

    int dfs(int now, int fm){
        int res1 = 0, res2 = 0;
        for(auto iter : edges[now]){
            int nto = iter;
            if(nto != fm){
                int res = dfs(nto, now);
                if(s[now] != s[iter]){
                    int tmp = res + 1;
                    if(tmp > res1) res2 = res1, res1 = tmp;
                    else if(tmp > res2) res2 = tmp;
                }
            }
        }
        ans = max(ans, res1 + res2 + 1);
        return res1;
    }
    
    
    int longestPath(vector<int>& parent, string s) {
        this->s = s, ans = 0;
        for(int i = 1; i < parent.size(); i++){
            int now = parent[i];
            edges[i].push_back(now), edges[now].push_back(i);
        }
        memset(dp, 0, sizeof(dp));
        dfs(0, -1);
        return ans;
    }
};