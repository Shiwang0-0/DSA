// You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.

// A substring is a contiguous sequence of characters within a string.
// Even after getting even number in end of string,remove the even number and return the remaining string with odd value at last(meaning whole string as odd).

//       Ex: input
//       num = "3542702"     
//       Output= "35427"      

// class Solution {
// public:
//     string largestOddNumber(string num) {
//         int i=num.length();
//         for(i-1;i>=0;i--)
//         {
//             if(num[i]&1)
//             {
//                 return num.substr(0,i+1);
//             }
//         }
//         return "";
        
//     }
// };