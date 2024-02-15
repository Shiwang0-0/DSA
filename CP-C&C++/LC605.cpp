/*

// Many edge cases

class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        
        int sz=bed.size();

        // check if n==0, if it is then flowers are already good to go
        if(n==0)
            return true;

        // if bed size is 1 return its not value
        // if 0 then plant the tree, if it is 1 then we can't plant.
        // NOTE: 0 <= n <= flowerbed.length so n can max be 1 only.
        if(bed.size()==1 )
            return !bed[0];

        // terminating the cases where first 2 elements are 0
        // means first element can have flower planted
        // as it will utilize the maximum flowers thus utilizing all n's.
        if(bed[0]==0 && bed[1]==0)
        {
            bed[0]=1;
            n--;
        }

        // check again for n
        if(n==0)
            return true;

        // terminating the cases where last 2 elements are 0
        // means last element can have flower planted
        // as it will utilize the maximum flowers thus utilizing all n's.
        if(bed[sz-1]==0 && bed[sz-2]==0)
        {
            bed[sz-1]=1;
            n--;
        }
        
        // check again for n
        if(n==0)
            return true;

        // now check for the empty plots
        // if their neighbours are empty then plant the flower.
        for(int i=1;i<bed.size()-1;i++)
        {
            if(bed[i]==0) // eligible for planting
            {
                // check neighbours
                if(bed[i-1]==0 && bed[i+1]==0)
                {
                    bed[i]=1;
                    n--;
                }
            }
            // check for n;
            if(n==0)
                return true;
        }

        // not all flowers are utilized, means n>0
        return false;
    }
};


*/