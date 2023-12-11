// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 
// will fail for very large array size. One possibility is that the integer division or arithmetic operations might be causing issues when dealing with very large numbers or long sequences of integers in the array.
// Also The current algorithm has a time complexity of O(n), where n is the size of the array. However, if the array is very large, the constant factors within the algorithm or machine limitations might cause it to fail.

// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         int c=1,max=0,ans;
//         int size=arr.size();
//         if(size==1)
//         {
//             return arr[0];
//         }
//         for(int i=0;i<size-1;i++)
//         {
//             if(arr[i]==arr[i+1])
//             {
//                 c++;
//                 if(max<c)
//                 {
//                     max=c;
//                     ans=arr[i];
//                 }
//             }
//             else
//             {
//                 c=1;
//             }
//         }
//         if(((max*100))/size>25)
//         {
//             return ans;
//         }
//         return -1;
//     }
// };



//Approach 2
//divide arr into 4 parts for 25% each.
//as it is divided there will be a element (mentioned in the question only one such element with >25% exist in the array) for which the element will lie in the other quaters.so match for i and quaterSize+i. Loop will execute till size and as we have arr[quatersize+i] so i should go maximum size-quaterSize-1 in the for loop. 

// class Solution {
// public:
//     int findSpecialInteger(vector<int>& arr) {
//         int size=arr.size();
//         int quaterSize=size/4;
//         for(int i=0;i<size-quaterSize;i++)
//         {
//             if(arr[i]==arr[quaterSize+i])
//             {
//                 return arr[i];
//             }
//         }
//         return -1;
//     }
// };