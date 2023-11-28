// // Pascal's Triangle
// // Input: numRows = 5
// // Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]



// // ITERATIVE SOLUTION

// // class Solution
// // {
// // public:
// //     vector<vector<int>> generate(int numRows)
// //     {
// //         vector<vector<int>> result;
// //         for (int i = 0; i < numRows; i++)
// //         {
// //             vector<int> levelAns(i + 1, 1);
// //             // vector <int> v(5,4)
// //             //  In C++, this syntax creates a vector of integers with 5 elements, each initialized to            the value 4. If you print this vector, you'll see something like: [4, 4, 4, 4, 4].
// //             for (int j = 1; j < i; j++)
// //             {
// //                 levelAns[j] = result[i - 1][j - 1] + result[i - 1][j];
// //             }
// //             result.push_back(levelAns);
// //         }
// //         return result;
// //     }
// // }



// // RECURSIVE SOLUTION

// class Solution
// {
// public:
//     vector<vector<int>> generate(int numRows) 
//     {
 
//         if (numRows == 0)
//         {
//             return {};
//         }
//         if (numRows == 1)
//         {
//             return {{1}};
//         }

//         vector<vector<int>> prev = generate(numRows - 1);
//         vector<int> result(numRows, 1);
//         for (int i = 1; i < numRows - 1; i++)
//         {
//             result[i] = prev.back()[i - 1] + prev.back()[i];
//         }
//         prev.push_back(result);
//         return prev;
//     };
// }
