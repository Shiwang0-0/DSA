class Solution {

private:
    bool funcDP(string &s,string&t,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0 && j<0)
            return true;
        
        if(i>=0 && j<0)
            return false;

        if(i<0 && j>=0) // only happpen when the s has already become empty and string t is all *.
        /// because then the each remaining * can represent an empty string.
        {
            for(int k=0;k<=j;k++)
            {
                if(t[k]!='*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        if(s[i]==t[j] || t[j]=='?')
            return dp[i][j]=funcDP(s,t,i-1,j-1,dp);

        else if(t[j]=='*')
        {
            // this condition is like a for loop where you take none character,
            // then take 1 character,
            // then take 2 characters and so on.

            bool val1=funcDP(s,t,i-1,j,dp);// either consider the character in star and move on from the character
            bool val2=funcDP(s,t,i,j-1,dp);// or consider * as empty and move on from *
            return dp[i][j]= val1 || val2;
        }
        return dp[i][j]=false;
    }

public:
    bool isMatch(string s, string t) {
        // * here doesnt signifes the * from automata.
        // here * can consist of different characters.
        // so for a case like 
        // "aasdsdsaaasds"           "aasds*sds" 
        // ans is true since * here is dsaaa

        // note: only string t contains * and ? shit.

        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return funcDP(s,t,n-1,m-1,dp);
    }
};