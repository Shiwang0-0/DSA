//Factorial of large numbers. TC:O(n^2)   SC:O(1)

// class Solution {
// public:

//     void fact(vector<int>&ans,int n)
//     {
//         int carry=0;
//         int size=ans.size();
//         for(int i=0;i<size;i++)
//         {
//             int product=ans[i]*n+carry;
//             ans[i]=product%10;
//             carry=product/10;
//         }
//         while(carry)
//         {
//             ans.push_back(carry%10);
//             carry=carry/10;
//         }
//     }
                

//     vector<int> factorial(int N){
        
//         vector<int>ans;
//         ans.push_back(1);
//         for(int i=2;i<=N;i++)
//         {
//            fact(ans,i);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
        
//     }
// };
