class Solution {
public:
    int tot[550];
    bool divideArray(vector<int>& nums) {
        for(auto &num : nums){
            tot[num]++;
        }
        int flag = 1;
        for(auto &num : nums){
            flag = flag && (tot[num] % 2 == 0);
        }
        return flag;
    }
};