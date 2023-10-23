class Solution {
   bool check(const int n){
        if(n==0)    
            return false;
        if(n==1)    
            return true;
        if(n%4!=0)
            return false;
        return check(n/4);
    }
    
public:
    bool isPowerOfFour(int n) {
        return check(n);
    }
};
