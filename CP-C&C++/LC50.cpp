/*

APPROACH: 1  BINARY EXPONENTIATION O(logn)

class Solution {
public:

    double solve(double x,int n)
    {
        if(x>=pow(2,31)-1)
            return 1;
        if(x<=-pow(2,31))
            return 1;
        if(n==0)
            return 1;
        if(n==1)
            return x;
        
        double val=solve(x,n/2);

        if(n%2==0)
        {
            return val*val;
        }
        else
        {
            // if(n<0)
            //     return (1.0)/val*val*x;
            return val*val*x;
        }
    }

    double myPow(double x, int n) {
        if(x==1)
        {
            return 1;
        }
        if(n==1)
            return x;

        if(n<0)
        return 1.0/solve(x,n);
        else
        return solve(x,n);

    }
};


APROACH 2: EXPONENTS O(logn)

LOGIC:
x^n=somthing
n log(x)=log something
ans=log something
something=e power ans

class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)
        {
            return 1;
        }
        if(n==1)
            return x;

        double ans=n*log(x);
        if(x<0){
            if(n%2 ==0){
                return exp(n*(log(-x)));
            }
            else
                return -exp(n*(log(-x)));
        }

        return exp(ans);

    }
};


*/