class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,h=nums.size()-1;
        while(lo<=h)
        {
            int mid=lo+(h-lo)/2;
            if(nums[mid]==target)
                return mid;
            
            if(nums[lo]<=nums[mid]){
                if(target<nums[mid] && target>=nums[lo])
                    h=mid-1;
                
                else 
                    lo=mid+1;
            }
            else if(nums[mid]<=nums[h]){
                if(target>nums[mid] && target<=nums[h])
                    lo=mid+1;
                
                else 
                    h=mid-1;
            }
        }
        cout<<h;
        return -1;
    }
};