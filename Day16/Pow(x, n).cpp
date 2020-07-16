class Solution {
public:
    double myPow(double x, int n) {
       // double ans ;
        if(n<0)
            return negativePow(x,n);
        else
            return positivePow(x,n);
    }
    
    double positivePow(double x,int n ){
        if(n==0)
            return 1.00;
       double ans = positivePow(x,n/2);
        
        if(n%2==0)
            return ans*ans;
        else
            return x*ans*ans;
    }
    double negativePow(double x,int n ){
        if(n==-1)
            return 1/x;
       double ans = negativePow(x,n/2);
        
        if(n%2==0)
            return ans*ans;
        else
            return (1/x)*ans*ans;
    }
};
