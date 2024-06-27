
class Solution {
public:
    int numSquares(int n) {

        // ans could be 1, that is sqrt(n)*sqrt(n)
        // ans could be 2,  Pythagoraus
        // ans could be 3, Three square sum
        // ans could be 4, Four square sum
        
        // Sqrt
        if(double(sqrt(n))==int(sqrt(n)))
            return 1;
        

        // Pythagoraus
        // if n is perfect square representable in sum of squares of two, then it should follow pythagoraus.

        // n^2=x^2+y^2;
        // thinking of n as perfect square it will be, ( asumption for now )
        // x^2=n-y^2
        // if x comes out to be a perfect square then all above senarios are true

        double sqrtN=sqrt(n);
        for(int i=1;i<=sqrtN;i++)
        {
            int x=n-i*i;
            if(int(sqrt(x))==double(sqrt(x)))
                return 2;
        }


        // Four Square sum
        while(n%4==0)
            n=n/4;
        if(n%8==7)
            return 4;

        return 3;

    }
};