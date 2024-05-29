class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
        for(int i=0;i<bills.size();i++)
        {
            if(bills[i]==5)
            {
                five++;
            }
            else if(bills[i]==10)
            {
                if(five==0)
                    return false;
                five--;
                ten++;    
            }
            else if(bills[i]==20)
            {
                
                // main crux is you use minimum number of 5 first and maximum number of ten possible.
                // because 5 is smaller denomination and we may need those extra fives in future
                if(five>=1 && ten>=1)
                {
                    five-=1;
                    ten--;
                }
                else if(five>=3 && ten==0)
                {
                    five-=3;
                }
                else
                    return false;
            }
        }
    return true;
    }
};