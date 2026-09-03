// 123
// 456
// 789

// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int n,count=1,j=1;
//     cin >>n;
//     for (int i = 1; i <= sqrt(n); i++)
//     {
//         for (j=1 ; j <= sqrt(n); j++)
//         {
//             cout<<count<<" ";
//             count++;
//         }
//         cout<<endl;
        
//     }
    
//     return 0;
// }







// *
// **
// ***
// ****

// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     for (int j = 0; j < n; j++)
//     //     {
//     //         if (i<j)
//     //         {
//     //             cout<<" ";
//     //         }
//     //         else{
//     //             cout<<"*";
//     //         }
            
//     //     }
//     // cout<<endl;
//     // }


//     // ALTERNATIVE

//     // for (int i = 1; i <= n; i++)
//     // {
//     //     for (int j = 1; j <= i; j++)
//     //     {
//     //         cout<<"*";
//     //     }
//     //     cout<<endl;
//     // }
    
    
//     return 0;
// }






// 1
// 23
// 345
// 4567    

// #include<iostream>
// using namespace std;

// int main()
// {
//     int n,count;
//     cin>>n;
//     // for (int i = 1; i <= n; i++)
//     // {
//     //     count=i;
//     //     for ( int j = 1; j <=i; j++)
//     //     {
//     //         cout<<count;
//     //         count++;
//     //     }
//     //     cout<<endl;
//     // }

//     //   ALTERNATIVE(without declaring count variable)

       
        



    
//     return 0;
// }





// ABC
// DEF
// GHI

// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     char c='A';
//     cin>>n;
//     int j=0;
//     for (int i = 0; i < n; i++)
//     {
        
//         for ( j=0 ; j < n; j++)
//         {
            
//             cout<<c; 
//             c=c+1;
            
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }




// ABC 
// BCD 
// CDE 
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     char c='A',ch;

//     for (int i = 0; i < n; i++)
//     {
//         c='A';
        
//         for (int j = 0; j < n; j++)
//         {
//             ch=c+j+i;
//             cout<<ch;
//         }
//     cout<<endl;
//     }
    
//     return 0;
// }




#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    char ch='A',val;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <=i; j++)
        {
            val=ch+i+j;
            cout<<val;
            
        }
        cout<<endl;
    }
    
    return 0;
}
