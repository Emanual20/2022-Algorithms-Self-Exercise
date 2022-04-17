class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        for(int i = 0; i < operations.size(); i++){
            int nfm = operations[i][0], nto = operations[i][1];
            int need = gem[nfm] / 2;
            gem[nfm] -= need, gem[nto] += need;
        }
        
        int ret = 0, maxi = -1, mini = 1e8;
        for(int i = 0; i < gem.size(); i++){
            maxi = max(maxi, gem[i]), mini = min(mini, gem[i]);
        }
        ret = maxi - mini;
        return ret;
    }
};