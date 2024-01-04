// Minimum Number of Operations to Make Array Empty
// Little Maths 

// T.c: O(N)

// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         unordered_map<int,int>m;
//         for(int n:nums)
//         {
//             m[n]++;
//         }
//         int c=0;
//         for(auto a:m)
//         {
//             int val=a.second; //thats where the count is
//             if(val==1)
//                 return -1;
//             c=c+(val/3); //if multiple of 3 then operation 2nd can be done.
//             if(val%3) //if not multiple of 3 then either 2 elements must be left only so operation 1 is performed or 1 element is left meaning we take 1 from the 3 group and 1 this current element which is left alone making a pair of them.
//             c++;
//         }
//         return c;
//     }
// };