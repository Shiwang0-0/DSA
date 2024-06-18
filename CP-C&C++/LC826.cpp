class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int,int>m;

        // if difficulty is repeated, make sure to store the maximum profit achievable in that same difficulty
        for(int i=0;i<difficulty.size();i++)
        {
            if(m.find(difficulty[i])!=m.end())
                m[difficulty[i]]=max(profit[i],m[difficulty[i]]);
            else
                m[difficulty[i]]=profit[i];
        }

        sort(worker.begin(),worker.end());
        sort(difficulty.begin(),difficulty.end());

        int maxProfitSoFar=0;
        for(auto it:m)
        {
            int prof=it.second;
            int diff=it.first;
            maxProfitSoFar=max(maxProfitSoFar,prof);
            m[diff]=maxProfitSoFar;
        }

        int j=0,ans=0,maxi=0;
        for(int i=0;i<worker.size();i++)
        {
            int cap=worker[i];
            while(j<difficulty.size() && cap>=difficulty[j])
                j++;
            if(j-1>=0)
                ans+=m[difficulty[j-1]];
        }

        return ans;
    }
};



----------------------------------------------------------------------------------------------------


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxDiff=0,ans=0;

        // find max possible difficulty
        for(int i=0;i<difficulty.size();i++)
        {
            maxDiff=max(maxDiff,difficulty[i]);
        }

        // make a vector of max possible diffiuclty size
        vector<int>maxProfitTillThatDiff(maxDiff+1);

        // for every difficulty present in the diff array, find the max profit it can achive.
        // it also take care of 2 difficulty being same
        for(int i=0;i<difficulty.size();i++)
        {
            maxProfitTillThatDiff[difficulty[i]]=max(maxProfitTillThatDiff[difficulty[i]],profit[i]);
        }

        // for values which are not present in the diff array, the maxProfit we can gain will be equal to the previous elements value only.
        for(int i=1;i<maxDiff+1;i++)
        {
            maxProfitTillThatDiff[i]=max(maxProfitTillThatDiff[i],maxProfitTillThatDiff[i-1]);
        }


        // if capacity is less than maxDiff means we have to take the corresponding profit only,
        // but if cap exceeds maxDiff we can take maxdiff profit 
        for(int i=0;i<worker.size();i++)
        {
            int cap=worker[i];
            if(cap>maxDiff)
            {
                ans=ans+maxProfitTillThatDiff[maxDiff];
            }
            else
            {
                ans=ans+maxProfitTillThatDiff[cap];
            }
        }
    return ans;
    }
};