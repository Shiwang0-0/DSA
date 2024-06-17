class Solution {
public:
    bool isPerfectSquare(int num) {
        // fact that all perfect squares are sum of odd number starting from 1;
        int i=1;
        while(num>0)
        {
            num=num-i;
            i+=2;
            if(num==0)
                return true;
        }
        return false;
    }
};

//---------------------------------------------------------------------------------------------------

class Solution {
public:
    bool isPerfectSquare(int num) {

        // binary search
        long long s=1,e=num;
        while(s<=e)
        {
            long long mid=s+((e-s)/2);
            long long sq=mid*mid;
            if(sq==num)
                return true;
            if(sq>num)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        return false;
    }
};