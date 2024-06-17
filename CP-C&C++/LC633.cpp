// Prerequisit Fermat's Theorem- https://www.youtube.com/watch?v=cZXVlhiXSwI



// Mix of Fermat's and basic math

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        if(c%4==3) // comes from fermat's theorem
            return false;

        for (long a = 0; a * a <= c; ++a) {
        double b = sqrt(c - a * a);
        if (b == static_cast<int>(b)) {
            return true;
        }
        }
        return false;

        if(c%4==3)
            return false;      
    }
};




// Pure Fermet's theorem

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        if(c<=2)
            return true;

        while(c%2==0) c/=2; // to deal with number like 6, that are many 2's say a can represent them so remove those,
        // but for the remaining 3 we need b which will be check further.

        if(c%4==3) // comes from Fermet's theorem
            return false;
        
        int val=sqrt(c);
        for (int i=3;i<=val;i+=4) // fermat's theorem says 4k+3 is the representation of the prime number, if any factor of it is found odd number of time then 
        // the number cannot be represented as sum of square of 2 numbers
        {
            int count=0;
            if (c%i==0) 
            {
                while (c%i==0) 
                {
                    count++;
                    c=c/i;
                }
                // If k of the form 4k+3 has an odd exponent, return false
                if (count%2!=0)
                    return false;
            }
        }
    return true;
    }
};

