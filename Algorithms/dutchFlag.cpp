#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid=0;
        int store=high;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else if(nums[mid]==2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }

int main()
{
    vector<int> v={2,0,2,1,1,0,2,1,2,1,2,1,2,1,2,2,2,2,2,0,0,0,0,0,2,1,2,1,1,1,2,1,2,1,1,0,1};
    sortColors(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i];
    }
    
    return 0;
}