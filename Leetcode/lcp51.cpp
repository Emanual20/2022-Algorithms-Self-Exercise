class Solution {
public:
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks, vector<vector<int>>& attribute, int limit) {
        int ans = -1;
        
        int len = cookbooks.size();
        for(int i = 0; i < (1 << len); i++){
            vector<int> now(5, 0);
            int deli = 0, full = 0;
            for(int j = 0; j < len; j++){
                if((i >> j) & 1){
                    for(int k = 0; k < 5; k++){
                        now[k] += cookbooks[j][k];
                    }
                    deli += attribute[j][0], full += attribute[j][1];
                }    
            }
            if(full >= limit 
               && now[0] <= materials[0] 
               && now[1] <= materials[1] 
               && now[2] <= materials[2]
               && now[3] <= materials[3]
               && now[4] <= materials[4]){
                ans = max(ans, deli);
            }
        }
        
        return ans;
    }
};