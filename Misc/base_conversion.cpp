//DECIMAL TO BINARY
// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int n,bit;
//     float number=0.0; //consider using float type and not int it is because when we pass a value in pow (10,1) it takes it as a double so the output shown will be 10.0000000^1.0000000 while computing it the the output shown will be wrong not 10 it will be 9.99999999 and it converts it into int as we are assigning it a int so the value shown is 9 the best method is add 0.000000001 to pow in brackets rather than converting it to float after computing it the the value goes to 10.000000001 it gets converted to 10.
//     cin>>n;
//     for (int i = 0 ; n!=0; i++)
//     {
//         bit= n & 1;
        




    //************* BINARY OF A NEGATIVE  NUMBER **********


//NAHI AAYA 


//????????????????????????????????????????









        
//         // number=number+(pow(10,i)*bit); prints the actual binary(kyuki hum reverse mai hi to calculate kerte hai binary.)
//         number=number*10+bit; //print the reverse of the binary
//         n=n >> 1;
//     }  
//     cout<<number;

  
//     return 0;
// }




// CONVERTING BINARY TO DECIMAL
// #include<iostream>
// #include<cmath>
// using namespace std;

// int main()
// {
//     int n,bit,number=0,i=0;
//     cin>>n;
//     while (n!=0)
//     {
//         bit=n%10; // & cannot be used bease it will work on the binary of n but here w eneed the idgits of n.
//         if (bit==1)
//         {
//             number=number+pow(2,i);
//         }
//         n=n/10;
//         i++;
//     }
//     cout<<number;
//     return 0;
//}


// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int product=1;
//     for (int i = 0; ; i++)
//     {
//         product=product*2;
//         if (product>n)
//         {
//             cout<<"not in power of 2";
//             break;
//         }
//         else if(product==n)
//         {
//             cout<<"in power of 2";
//             break;
//         }
//         else{
//             continue;
//         }
        
//     }
    
    
//     return 0;
// }





