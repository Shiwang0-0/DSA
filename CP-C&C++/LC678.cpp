
// Normal Recursion
// T.C: O(N^3)
// S.C: O(1)

// DP
// T.C: O(N^2)
// S.C: O(N^2)

class Solution {

private:

    // will do c+1 for left
    // c-1 for right
    // c for *
    bool funcDP(string s,int i,int c,vector<vector<int>>&dp)
    {
        if(c<0 || i>s.length())
            return false;
        if(i==s.length())
            return c==0;
        
        if(dp[i][c]!=-1)
            return dp[i][c];

        bool left=false,right=false,none=false,normal=false;

        if(s[i]=='*')
        {
            left=funcDP(s,i+1,c+1,dp);
            right= funcDP(s,i+1,c-1,dp);
            none=funcDP(s,i+1,c,dp);
        }
        else
        {
            if(s[i]=='(')
                normal=funcDP(s,i+1,c+1,dp);
            if(s[i]==')')
                normal=funcDP(s,i+1,c-1,dp);
        }

        if(left || right || none || normal)
            return dp[i][c]=true;
        return dp[i][c]=false;   
    }

public:
    bool checkValidString(string s) {
        
        // Recursive DP
        int n=s.length();
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return funcDP(s,0,0,dp);
    }
};



// ------------------------------------------------------------------------------



// Range Method
// T.C: O(N)
// S.C: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int mini=0,maxi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                mini=mini+1;
                maxi=maxi+1;
            }
            else if(s[i]==')')
            {
                mini=max(0,mini-1);
                maxi=maxi-1;
            }
            else
            {
                mini=max(0,mini-1);
                maxi=maxi+1;
            }
            if(maxi<0) // if anytime maxi goes less than 0, return false.
            return false;
        }
        if(mini==0 && maxi>=0)
            return true;
        return false;
    }
};