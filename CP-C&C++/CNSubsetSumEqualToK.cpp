/*

// MEMOIZATION

#include <bits/stdc++.h> 

bool funcDP(vector<int> &arr,vector<vector<int>> &dp,int n,int k,int i,int sum)
{
    if(sum==k)
        return true;

    if(i==n || sum>k)
    {
        return false;
    }
    if(dp[i][sum]!=-1)
        return dp[i][sum];

    bool take=funcDP(arr,dp,n,k,i+1,sum+arr[i]);
    bool notTake=funcDP(arr,dp,n,k,i+1,sum);
    return dp[i][sum]=take || notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    if(n==0)
        return 0;
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return funcDP(arr,dp,n,k,0,0);
}
*/


// TABULATION

/*
#include <bits/stdc++.h> 


bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    // going from 0 to n.

    vector<vector<bool>>dp(n,vector<bool>(k+1,0)); // <index,target required>
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true; // where target req is already 0,mark them true.
    }
    if(arr[0]  <= k) // checking out of bound.
        dp[0][arr[0]]=true;
    for(int i=1;i<n;i++)
    {   
        for(int target=1;target<=k;target++)
        {
            bool notTake=dp[i-1][target];
            bool take=false;
            if(target>=arr[i])
            {
                take=dp[i-1][target-arr[i]];
            }
            dp[i][target]=take || notTake;
        }
    }
    return dp[n-1][k];
}
*/



// SPACE OPTIMIZATION

/*
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.

    // going from 0 to n.
    vector<bool>dp(k+1,false); 
    
    dp[0]=true; // for target =0 mark true
    if(arr[0]<=k)  // checking bound
        dp[arr[0]] = true; // for index 0 and mark taget true for the target required.
    for(int i=1;i<n;i++)
    {   vector<bool>curr(k+1,false);
        curr[0]=true;
        for(int target=1;target<=k;target++)
        {
            bool notTake=dp[target];
            bool take=false;
            if(target>=arr[i])
            {
                take=dp[target-arr[i]];
            }
            curr[target]=take || notTake;
        }
        dp=curr;
    }
    return dp[k];
}
*/