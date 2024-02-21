// KOKO EATING BANANAS

/*
class Solution {
public:

    long long solve(vector<int>piles, int bananaHourly)
    {
        long long n=0;
        for(int i=0;i<piles.size();i++)
        {
           n += ceil((double)piles[i] / (double)bananaHourly);
        }
        return n;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long hrsRequired=0;
        int mid=0;
        int e=*max_element(piles.begin(),piles.end());
        // int s=*min_element(piles.begin(),piles.end());
        int s=1;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            hrsRequired=solve(piles,mid);
            if(hrsRequired<=h)
                e=mid-1;
            else
                s=mid+1;
        }
    return s;
    }
};
*/