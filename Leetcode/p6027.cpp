class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ret = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l_index = -1, r_index = -1;
            for(int j = i; j >= 0; j--){
                if(nums[j] != nums[i]){
                    l_index = j;
                    break;
                }
            }
            
            for(int j = i; j < nums.size(); j++){
                if(nums[j] != nums[i]){
                    r_index = j;
                    break;
                }
            }
            
            if(l_index == -1 || r_index == -1) continue;
            else if(nums[i] > nums[l_index] && nums[i] > nums[r_index]){
                ret++;
            }
            else if(nums[i] < nums[l_index] && nums[i] < nums[r_index]){
                ret++;
            }
        }
        return ret;
    }
};