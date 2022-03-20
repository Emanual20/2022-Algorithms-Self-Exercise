class Solution {
public:
    int countCollisions(string directions) {
        int tot = 0, lens = directions.length(), ret = 0;
        for(int i = 0; i < lens; i++){
            if(directions[i] == 'L'){
                if(tot > 0) ret += (tot > 0);
            }
            else{
                tot++;
            }
        }
        
        tot = 0;
        for(int i = lens - 1; i >= 0; i--){
            if(directions[i] == 'R'){
                if(tot > 0) ret += (tot > 0);
            }
            else{
                tot++;
            }
        }
        
        return ret;
    }
};