class Solution {
public:
    int largestInteger(int num) {
        vector<int> vec;
        while(num){vec.push_back(num%10), num /= 10;}
        vector<int> v0, v1;
        for(int i = vec.size() - 1; i >= 0; i--){
            if(vec[i] % 2 == 0) v0.push_back(vec[i]);
            else v1.push_back(vec[i]);
        }
        sort(v0.begin(), v0.end(), greater<int>());
        sort(v1.begin(), v1.end(), greater<int>());
        int off0 = 0, off1 = 0;
        for(int i = vec.size() - 1; i >= 0; i--){
            if(vec[i] % 2 == 0) vec[i] = v0[off0++];
            else vec[i] = v1[off1++];
        }
        int ret = 0;
        for(int i = vec.size() - 1; i >= 0; i--){
            ret *= 10;
            ret += vec[i];
        }
        return ret;
    }
};