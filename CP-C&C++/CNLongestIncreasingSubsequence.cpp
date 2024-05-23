// FOR PRINTING LONGEST INCREASING SUBSEQUENCE

// Hashing ( making a hash array and linking dp array to it ) way to print ( NOT REGULAR TABULATION )

/*
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here

	// not you regular tabulation
	vector<int>dp(n,1);
	vector<int>hash(n,1);


	for(int i=0;i<n;i++)
	{
		hash[i]=i;
		for(int j=0;j<i;j++)
		{
			if(arr[j]<arr[i] && dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				hash[i]=j;
			}
		}	
	}

	int val=dp[0];
	int hashIdx=0;
	for(int i=1;i<n;i++)
	{
		if(dp[i]>val)
		{
			val=dp[i];
			hashIdx=i;
		}
	}

	vector<int>v;
	v.push_back(arr[hashIdx]);
	while(hashIdx!=hash[hashIdx])
	{
		hashIdx=hash[hashIdx];
		v.push_back(arr[hashIdx]);	
	}

// Actual Longest increasing subsequence
	// for(int i=v.size()-1;i>=0;i--)
	// 	cout<<v[i]<<" ";

	reverse(v.begin(),v.end());
	return v;
}
*/



// -----------------------------------------------------------------------------------



// FOR FINDING LENGTH

/*

TLE: RECURSIVE WAY

class Solution {

private:
    int func(vector<int>&nums,int prev,int n)
    {
        if(n==nums.size())
            return 0;
        
        int take=0;
        if(prev<nums[n])
            take=1+func(nums,nums[n],n+1);
        int notTake=func(nums,prev,n+1);
        return max(take,notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,func(nums,INT_MIN,i));
        }
        return ans;
    }
};
*/



// -----------------------------------------------------------------------------------




// since the previous approach usses INT_MIN i cannot use dp there ( out of bound 2D dp)


// FOR FINDING LENGTH

/*
class Solution {

private:
    int funcDP(vector<int>&nums,vector<vector<int>>&dp,int n,int prev)
    {
        if(n==nums.size())  
            return 0;

        if(dp[n][prev+1]!=-1)
            return dp[n][prev+1];

        int take=0;
        if(prev==-1 || nums[prev]<nums[n])  
            take=1+funcDP(nums,dp,n+1,n);
        int notTake=funcDP(nums,dp,n+1,prev);

        return dp[n][prev+1]=max(take,notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));  // <size,prev>
        // since prev is -1 initially, so make n+1 size for previous
        return funcDP(nums,dp,0,-1);
    }
};
*/



// -----------------------------------------------------------------------------------



// not your regular tabulation. 
// can be done using regular tabulation too.

// this tabulation is helpful if you want to print the LIS.
// you will need another hash vector to do so.

// FOR FINDING LENGTH

/*
class Solution {


public:
    int lengthOfLIS(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int>dp(n,1);

	    for(int i=0;i<n;i++)
	    {
	    	for(int j=i-1;j>=0;j--)
	    	{
	    		if(arr[j]<arr[i])
	    		{
	    			dp[i]=max(dp[i],1+dp[j]);
	    		}
	    	}	
	    }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};

*/
