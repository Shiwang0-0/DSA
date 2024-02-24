/*
int solve(int maxDist,vector<int>v)
{
    int cows=1,diff=0;
    int first=v[0];
    for(int i=1;i<v.size();i++)
    {
        diff=v[i]-first;
        if(diff>=maxDist)
        {
            first=v[i];
            cows+=1;
        }
    }
    return cows;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int low=0;
    int high=*max_element(stalls.begin(),stalls.end());
    sort(stalls.begin(),stalls.end());
    int mid=0,num=0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        num=solve(mid,stalls);
        if(num>=k) // if move left, cows will be utilized fast,so move right
            low=mid+1;
        else
            high=mid-1; // count of cows will increase when possible distance between them  will decrease. 
            // aur size shirnk hoga means minimum distance, means is case mai high return hoga
            // if size shrinks, means minimum distance ans thats what we want means here high will be returned.
    }
    return high;
}
*/