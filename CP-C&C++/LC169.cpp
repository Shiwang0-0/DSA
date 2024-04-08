
// Moore's Voting Algorithm

// travel the array, mark ele as first element
// if you get ele again increment count by 1
// if you encounter any other element decrement count by 1
// if count becomes 0, change your ele value to next position element where it become zero

// finally if count value is not zero, means the ele exist, return it.

/*

// Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int ele=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(!count)
                ele=nums[i];

            if(nums[i]==ele)
                count++;
            else
                count--;    
        }
        // count doesnt represents anything

        // as it states that the array always have a majority element,
        // because it may be possible that say 2 is major, but 2 is not begin repeated more than n/2 times
        // we dont need to check wether the count > n/2 because count being !-0 justify that


        if(count)
            return ele;
        return -1;
    }
};
*/