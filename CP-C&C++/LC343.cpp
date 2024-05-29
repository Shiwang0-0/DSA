
class Solution {


// why special
// there are multiple conditions to confuse
// need sum == target
// need max product of elements considered
// need atleast 2 elements to be considered

// just focus on max product, 
// base case will do sum==target check
// for loop will do inclusion of atleast 2 elements check

int funcDP(int n,vector<int>&dp)
{
    if(n==1)
        return dp[n]=1;
    
    int maxi=0;

    if(dp[n]!=-1)
        return dp[n];

    for(int i=1;i<n;i++) // dont break at 0th index
    // dont break at nth index
    // since they will take only 1 element, but k>=2. 
    {
        int base=i*(n-i);
        int recursive=i*funcDP(n-i,dp);
        int prod=max(base,recursive);
        maxi=max(maxi,prod);
    }
    return dp[n]=maxi;
}

public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return funcDP(n,dp);
    }
};



// ----------------------------------------------------------------------------------------



// MIND FUCK MATH

// READ: Alon Amit's 
// https://www.quora.com/Math-question-You-are-allowed-to-take-as-many-positive-whole-numbers-as-you-want-that-add-up-to-20-and-then-multiply-them-together-What-is-the-biggest-possible-result-you-can-get

class Solution {

public:
    int integerBreak(int n) {

        if(n==2)
            return 1;
        if(n==3)
            return 2;

        int howManyTwos=0;
        int howManyThrees=n/3;
        int remaining=n%3;
        if(remaining==1)
        {
            howManyThrees--;
            remaining+=3;
        }

        if(remaining)
            return remaining*(pow(3,howManyThrees));
        
        return pow(3,howManyThrees);
    }
};