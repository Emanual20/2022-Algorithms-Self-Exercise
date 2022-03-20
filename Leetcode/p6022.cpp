class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<long double, vector<long double>> pq;
        long double sum = 0, res = 0;
        int tot = 0;
        for(auto &num : nums){
            pq.push(num);
            sum += num;
        }
        
        while(sum > res * 2){
            long double now = pq.top();
            pq.pop();
            res += now / 2, tot++;
            pq.push(now / 2);
        }
        return tot;
    }
};