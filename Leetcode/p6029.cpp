class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int maxi = 0, maxi_index = -1;
        for(int i = 0; i < (1 << 12); i++){
            int now_use = 0, now_score = 0;
            for(int j = 0; j < 12; j++){
                if(i & (1 << j)){
                    now_use += (aliceArrows[j] + 1);
                    now_score += j;
                } 
            }
            if(now_use <= numArrows && now_score > maxi){
                maxi = now_score;
                maxi_index = i;
            }
        }
        
        vector<int> ret(12);
        int tmp = 0;
        for(int i = 0; i < 12; i++){
            if(maxi_index & (1 << i)){
                ret[i] = aliceArrows[i] + 1;
                tmp += (aliceArrows[i] + 1);
            }
        }
        ret[11] += (numArrows - tmp);
        
        return ret;
    }
};