class Solution {
public:
    typedef long long ll;
    long long maximumSubsequenceCount(string text, string pattern) {
        ll ret = 0, lenp = text.length(), tot0 = 0, tot1 = 0;
        if(pattern[0] != pattern[1]){
            for(int i = lenp - 1; i >= 0; i--){
                if(text[i] == pattern[1]) tot1++;
                if(text[i] == pattern[0]) tot0++, ret+=tot1;
            }
            ret += max(tot0, tot1);
        }
        else{
            for(int i = lenp - 1; i >= 0; i--){
                if(text[i] == pattern[1]) tot0++;
            }
            ret = tot0 * (tot0 + 1) / 2;
        }
        return ret;
    }
};