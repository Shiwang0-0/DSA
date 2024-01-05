// Given an integer array nums of unique elements, return all possible subsets (the power set).


// class Solution {
// public:

//     void findSubSet(vector<int>nums, vector<int> temp,int start,int end,vector<vector<int>> &ans)
//     {
//        if(start>end)
//        {
//            ans.push_back(temp); //pushing the final round's 1D-vector into 2D-vector.
//            return;
//        }
        
//         // excluding: just increment index.
//         findSubSet(nums,temp,start+1,end,ans);

//         // including: pushing value in "1D-vector" 
//         int ele= nums[start];
//         temp.push_back(ele);
//         findSubSet(nums,temp,start+1,end,ans);
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> temp;
//         int len=nums.size();

//         vector<vector<int>>ans;
//         findSubSet(nums,temp,0,len-1,ans); 
//         return ans;
//     }
// };