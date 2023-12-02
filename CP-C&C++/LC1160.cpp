// You are given an array of strings words and a string chars.

// A string is good if it can be formed by characters from chars (each character can only be used once).

// Return the sum of lengths of all good strings in words.

 

// Example 1:

// Input: words = ["cat","bt","hat","tree"], chars = "atach"
// Output: 6
// Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.
// Example 2:

// Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
// Output: 10
// Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.




// class Solution {
// public:
//     int countCharacters(vector<string>& words, string chars) {
//         int c=0;

//         // Mark count of every element of chars in 26 alphabet representation.
//         vector<int> countChar(26,0);
//         for(int i=0;i<chars.size();i++)
//         {
//             char c=chars[i];
//             countChar[c-'a']++;
//         }

//         // In the given vector iterate through each word.
//         for(int i=0;i<words.size();i++)
//         {
//             bool success=true;
//             vector<int> tempCount(countChar);

//             // Vector tempCount stores the whole vector of counts for each alphabet.
//             for(int j=0;j<words[i].size();j++)
//             {
                

//                 // With each alphabet present in the list word count>0 less it by one,until the word end, until the list ends.
//                 char ch=words[i][j];
//                 if(tempCount[ch-'a']>0)
//                 {
//                     tempCount[ch-'a']--;
//                 }
//                 // If alphabet was missing from the given word but was present in the list then there will be failure
//                 else
//                 {
//                     success=false;
//                     break;
//                 }
//             }
//             // Add the word size if the word can succesfully be made from the given alphabets.
//             if(success)
//             {
//                 c=c+words[i].size();
//             }
//         }
//         return c;
//     }
// };