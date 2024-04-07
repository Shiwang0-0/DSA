

// MOST OPTIMAL FOR +VE AND -VE INCLUDED

/*AVG T.C: O(NlogN)   S.C: O(N)
NOTE: if considering unordered_map it is possible to attain O(N) if collisions are less
and also possible to have O(N^2) if more collisions are present.

#include <bits/stdc++.h>
#include <map> 
int getLongestSubarray(vector<int>& a, int k){
    // a map storing sum indexes where those sum are formed.
    map<long long,int>m;
    long long sum=0;
    int len=0;

    // traversing the vector and storing the sum
    // following reverse psychology method
    // if there is k then there must be a sum-k already present in the map.
    for(int i=0;i<a.size();i++)
    {
        sum=sum+a[i];

        // before storing into map, check if that value already exist 
        // if it does, it means for current i, 0 is added
        // as zero is added we do not need to change our i
        // because we requires the longest of the subarrays.
        if(m.find(sum)==m.end())
        {
            m[sum]=i;
        }
        // check if sum is formed just without finding the remaining in the map
        if(sum==k)
        {
            len=max(len,i+1);
        }

        long long remaining=sum-k;
        if(m.find(remaining) != m.end())
        {
            len=max(len,i-m[remaining]);
        }
    }

    return len; 
}
*/



// MOST OPTIMAL FOR +VE ONLY
// two pointer

// T.C: O(2N)  S.C: O(1)

/*
#include <vector>
#include<math.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int left=0,right=0;
    int len=0;
    int n=a.size();
    long long sum=a[0];
    while(right<n)
    {
        while(left<=right && sum>k)
        {
            sum-=a[left];
            left++;
        }
        if(sum==k)
        {
            len=max(len,right-left+1);
        }
        
        right++;
        if(right<n)
        sum=sum+a[right];
        
    }
    return len; 
}
*/