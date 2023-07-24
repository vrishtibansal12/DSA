class Solution {
    double my(double x, int n) {
        double nn=n;
        if(nn==0)
            return 1;
        if(nn<0){
            x=1/x;
            nn*=-1;
        }
        if(nn==1)
            return x;      
        if(n%2==0)
           return myPow(x*x, nn/2);
        else
           return myPow(x*x, nn/2)*x;
    }
public:
    double myPow(double x, int n) {
           return my(x,n);
    }
};