class Solution {
public:
    string digitSum(string s, int k) {
        string tmp = s;
        while(tmp.length() > k){
            string res = "";
            int now = 0, tot = 0;
            for(int i = 0; i < tmp.length(); i++){
                now += (tmp[i] - '0'), tot++;
                if(tot == k || i == tmp.length() - 1) res = res + to_string(now), now = 0, tot = 0;
            }
            tmp = res;
        }
        return tmp;
    }
};