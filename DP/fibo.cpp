

// MEMOIZATION
/*
T.C : O(N) // only a linear recursion is called, rest are there but they are computed using dp array.
S.C : O(N) + O(N)

#include<iostream>
using namespace std;

int fibo(int dp[],int n)
{
    if(n==0 || n==1)
        return n;
    
    if(dp[n]!=-1)  // if value is already calculated return the value from the stored array
        return dp[n];

    return dp[n]=fibo(dp,n-1)+fibo(dp,n-2);  // if value is not calculated, find it. make recursive calls for it.
}

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    for (int i = 0; i < n+1; i++)
    {
        dp[i]=-1; // making sure that the value is not yet calculated
    }
    
   cout<< fibo(dp,n);
   return 0;
}
*/




// TABULATION
// T.C : O(N)  
// S.C : O(N)

/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    
    dp[0]=0;
    dp[1]=1;
    for (int i = 2; i < n+1; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
   return 0;
} 
*/




// OPTIMAL
// T.C : O(N)  
// S.C : O(1)

#include<iostream>
using namespace std;


#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int prev=1;
    int prev2=0;
    int val=0;
    for (int i = 2; i < n+1; i++)
    {
        val=prev+prev2;
        prev2=prev;
        prev=val;
    }
    cout<<val;
    return 0;
} 









