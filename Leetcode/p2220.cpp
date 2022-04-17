class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ret = 0;
        for(int i = 0; i < 31; i++){
            int sn = start & (1 << i), gn = goal & (1 << i);
            ret += (sn != gn);
        }
        return ret;
    }
};