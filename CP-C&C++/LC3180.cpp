class Solution {

private:
    int funcDP(vector<int>&v,int n,int total,vector<vector<int>>&dp)
    {
        if(n<0)
            return 0;

        if(dp[n][total]!=-1)
            return dp[n][total];

        int take=0;
        if(total<v[n])
        {
            take=v[n]+funcDP(v,n-1,total+v[n],dp);
        }
        int notTake=funcDP(v,n-1,total,dp);

        return dp[n][total]=max(take,notTake);

    }

public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n=rewardValues.size(); 
        // this sort will help us in marking vis, we dont actually mark here, because recursion will go in one direction only, and therefore we will not see the elements again.
        // also since i have writtern recursion from n-1 to 0, i have to sort in descending order.
        // start from the lowest value first because there is one condition
        // If rewardValues[i] is greater than your current total reward x, then add rewardValues[i] to x
        sort(rewardValues.begin(),rewardValues.end(),greater<int>());
        // max sum could only go upto 4000. Reason is no value in arr is greater than 2000 so when the sum is >2000 u can never get any other element. So max two element u can get is 1999 + 2000.
        vector<vector<int>>dp(2001,vector<int>(4000,-1));
        return funcDP(rewardValues,n-1,0,dp);
    }
};