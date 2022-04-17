const int inf = 1e9 + 7;
class Solution {
public:
    int pow10[11];
    string minimizeResult(string expression) {
        pow10[0] = 1;
        for(int i = 1; i <= 9; i++) pow10[i] = pow10[i - 1] * 10;
        
        vector<int> ops;
        int now = 0;
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] == '+'){
                ops.push_back(now), now = 0;
            }
            else{
                now *= 10, now += (expression[i] - '0');
            }
        }
        ops.push_back(now);
        
        string sx = to_string(ops[0]), sy = to_string(ops[1]);
        int lenx = to_string(ops[0]).length(), leny = to_string(ops[1]).length();
        
        int idx = -1, idy = -1, maxi = inf;
        for(int i = 0; i < lenx; i++){
            for(int j = 1; j <= leny; j++){
                int sx0 = ops[0] / pow10[lenx - i], sx1 = ops[0] % pow10[lenx - i];
                int sy0 = ops[1] / pow10[leny - j], sy1 = ops[1] % pow10[leny - j];
                sx0 = (sx0 == 0 ? 1 : sx0), sy1 = (sy1 == 0 ? 1 : sy1);
                int tmp = sx0 * sy1 * (sx1 + sy0);
                if(tmp < maxi){
                    maxi = tmp, idx = i, idy = j;
                }
            }
        }
        
        string ret = sx.substr(0, idx) + "(" + sx.substr(0 + idx, lenx - idx);
        ret = ret + "+";
        ret = ret + sy.substr(0, idy) + ")" + sy.substr(0 + idy, leny - idy);
        return ret;
    }
};