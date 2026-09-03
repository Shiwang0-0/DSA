





// Given an array nums of integers, return how many of them contain an even number of digits.
// Input: nums = [12,345,2,6,7896]
// Output: 2
// Explanation: 
// 12 contains 2 digits (even number of digits). 
// 345 contains 3 digits (odd number of digits). 
// 2 contains 1 digit (odd number of digits). 
// 6 contains 1 digit (odd number of digits). 
// 7896 contains 4 digits (even number of digits). 
// Therefore only 12 and 7896 contain an even number of digits.


// #include<math.h>
// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int count=0;
//         for(auto const num : nums){
//             if(((int(log10(num)+1)) % 2) == 0){
//             count++;
//             }
//         }
//         return count;
//     }
// };


#include<iostream>
using namespace std;

int main()
{
    int n=5;
    int val1=n&1;
    n=n>>1;
    int val2=n&1;
    cout<<n<<" "<<val1<<" "<<val2;
    return 0;
}