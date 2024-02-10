/*
Binary Search in 2D matrix

T.c: O(log m*n)

Treat it as linear search only


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int low=0,high=m*n-1,mid=0;
        while(low<=high)
        {
            mid=(high+low)/2;
            if(matrix[mid/n][mid%n] == target)  // main curx is to find the mid position in 2D matrix
                return true;
            
            if(matrix[mid/n][mid%n] > target)
            {
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return false;
    }
}
*/