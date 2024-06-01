class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()); 

        
        // why sorting and not (nums[j]%nums[i]==0 || nums[i]%nums[j]==0)

        // first, can we really sort ?
        // since subset is asked and not subsequence,yes we can


        // A thread:

//         Assume I have a satisfying set of n elements, and in increasing order they are [a1, a2, a3 ..... an]. Now I'm giving a new element k, and I'm trying to determine if adding k would yield me a satisfying set. Then three case:
// case 1: if k < a1, I simply need to check if a1 % k == 0
// case 2: if k >= an, similarly just need to check if k % an == 0
// case 3: if a1 < k < an. This is the most annoying case, because I need to check if (ai % k == 0 || k % ai ==0) for every element 1<= i <= n.

// So to avoid case 3, we should always use a sorted array, to make sure that the new element that's given is either case 1 if we look from the largest number to the smallest number (or case 2 if otherwise)


        // also
        // The main purpose of sorting is to make sure that all divisors of an element appear before it. say 1,2 4,8
        //if 4 is divisible by 2 and 1
       //and 8 is divisible by 4 then it automatically means 8 is divisible by 2 and 1 also.
       // just like we check for increasing sequence.

        int n=nums.size();
        vector<int>dp(n,1);
	    vector<int>hash(n,1);

	    for(int i=0;i<n;i++)
	    {
	    	hash[i]=i;
	    	for(int j=0;j<i;j++)
	    	{
	    		if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
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
	    v.push_back(nums[hashIdx]);
	    while(hashIdx!=hash[hashIdx])
	    {
	    	hashIdx=hash[hashIdx];
	    	v.push_back(nums[hashIdx]);	
	    }

        // Actual Longest increasing subsequence
	    // for(int i=v.size()-1;i>=0;i--)
	    // 	cout<<v[i]<<" ";
	    return v;
    }
};