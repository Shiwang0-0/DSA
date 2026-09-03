//CALCULATE THE NUMBER OF ONE BIT(SET BIT) IN A NUMBER
//ex- in 11 there are 3 one bits.


// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int count = 0;
//         while(n!=0) {
            
//             //checking last bit (Basically using the concept of right shifting the binary of the number n.We shift it until the number becomes 0 i.e no 1 is left in it).
//             if(n&1) {
//                 count++;
//             }
//             n = n>>1;
//         }
//         cout<<count<<endl;
//     return 0;
// }





#include<iostream>
using namespace std;

int main()
{
    int a=4;
    if((a>>3)&1){
        cout<<"this checks for the remaining portion, and does not check the portion on which right shift is perfomed";

        // 4=> 0 1 0 0
        // when using 2 , a if expression becomes ( ( 0 1 means 2 )& 1 ) so the cout is printeed.
        // when using 3 , a if expression becomes ( ( 0 means 0 ) & 1 ) so cout is not printed
    }

    // if shifted part is not stored in the same variable, the pervious value is retained.
    cout<<a;
    return 0;
}