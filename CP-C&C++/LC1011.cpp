

/*

class Solution {
public:

    int solve(vector<int> weights, int capacity)
    {
        int load=0,daysReq=1;
        for(int i=0;i<weights.size();i++)
        {
            if(weights[i]+load > capacity)
            {
                load=0;
                daysReq++;
            }
            load=load+weights[i];
        }
        return daysReq;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int s=0,e=0;

        // specify s as max of all the elements (ensure that
        // atleast the maximum weight can be sent in a whole day)

        //specify e as sum of all the elements (ensure that 
        // if days is 1 all weights can be sent in one go)
        for(int i=0;i<weights.size();i++)
        {
            s=max(s,weights[i]);
            e=e+weights[i];
        }

        // as we have range specified and we have to look for the minimum weight
        // we can look for binary search too, and eliminating the weights greater than minimum ones
        // although this can be done using linear search too.

        while(s<=e)
        {
            int mid = s+(e-s)/2;

            int daysRequired = solve(weights,mid); // send mid and calculate
            // how many days does it required to fullfill this much of weight barrier.

            if(daysRequired<=days) // we have utilized less number of days,
            //  means each day more weights are sent
                e=mid-1; // means we have to reduce mid
            else
                s=mid+1;
        }
        return s;
    }
};
*/