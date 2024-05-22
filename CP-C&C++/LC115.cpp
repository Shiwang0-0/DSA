
class Solution {

private:
    ll funcDP(string& s,string& t,ll i,ll j,vector<vector<ll>>&dp)
    {
        // this j<0 will be above, because of possiblity of finding the substring first may be there.
        if(j<0) // means the string from whcih we were searching is exhausted is finished, means the string is achived.
            return 1;

        if(i<0) // meaning our string on which search was to be done is exhausted.
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==t[j])
        {
            return dp[i][j]=funcDP(s,t,i-1,j-1,dp)+funcDP(s,t,i-1,j,dp);
        }
        else
            return dp[i][j]=funcDP(s,t,i-1,j,dp);
    }

public:
    ll numDistinct(string s, string t) {
        ll n=s.length();
        ll m=t.length();

        vector<vector<ll>>dp(n,vector<ll>(m,-1));
        ll val=funcDP(s,t,n-1,m-1,dp);
        return dp[n-1][m-1];
    }
};




#define ll long long
class Solution {

public:
    ll numDistinct(string s, string t) {
        ll n=s.length();
        ll m=t.length();

        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        for(ll i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }

        // you can actually omit this, since dp is initualize with 0
        // for(ll i=1;i<=m;i++)  // i stars from 1, to avoid overwriting of dp[0][0]
        // {
        //     dp[0][i]=0;
        // }
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    if(dp[i-1][j-1]+dp[i-1][j]>=INT_MAX)  // if result is greater than INT_MAX, just dont consider it.
                    // or remove this condition and use double instead
                        continue;
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
       return dp[n][m];
    }
};