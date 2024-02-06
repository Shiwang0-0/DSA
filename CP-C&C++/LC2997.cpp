/*
Approach is to take last bit of every element in vector and perform XOR on them.
now compare the XOR result with last bit of k 
if they are equal there is no need to flip
taking 32 indicated the number of bits to be taken into consideration.
each time 0,1,2,3,......32 shifts occur.
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int c=0;
        for(int i=0;i<32;i++) // 2^32 bits are enough to fulfill input constraints.
        {
            int a=0;
            for(int j=0;j<nums.size();j++)
            {
                int ele=nums[j];
                if((ele>>i)&1) // doing &1 is must, because without it, it checks wheter the remaining number after right shift is 1 or not
                // we need to make it check for the right shifted element and not the remaining ones.
                    a=a^1;
            }
            if(((k>>i)&1)!=a) // similary logic of & here.
                c++;
        }
        return c;
    }
};
*/