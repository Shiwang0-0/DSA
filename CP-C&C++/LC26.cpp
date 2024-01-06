//  Remove Duplicates from Sorted Array

//APPROACH 1 (SET APPROACH)
// T.C: O(NlogN + N )  S.C: O(N)

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> st;
//         for(int i=0;i<nums.size();i++)
//         {
//             st.insert(nums[i]);  // insertion in set takes NlogN
//         }
//         int index=0;
//         for(auto it:st)
//         {
//             nums[index++]=it;
//         }
//         return index;
//     }
// };


//APPROACH 2 (2 POINTER)
// T.C: O(N)  S.C: O(1)

// class Solution {
// public:
//     int removeDuplicates(vector<int>& arr) {
//         int len=arr.size();
//         int i=0;
//         for(int j=1;j<len;j++)
//         {
//             if(arr[i]!=arr[j])
//             {
//                 arr[i+1]=arr[j];
//                 i++;
//             }
//         }
//         return i+1;
//     }
// };


