// #include<iostream>
// #include<string>
// using namespace std;

// int main()
// {
//     // char arr[6]={'a','b','c','d','e','\0'};
//     // arr[2]='\0';
//     // cout<<arr;

//     string s;
//     cin>>s;
//     s.at(2)='\0';
//     cout<<s;
//     return 0;
// }


// #include<iostream>
// #include<string>
// #include<algorithm>
// using namespace std;

// int main()
// {
//     string s;
//     int j;
//     char temp[100];
//     cin>>s;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s.at(i)==' ')
//         {
//             reverse(s.at(0),s.at(i));
//             j=0;
//         }
//         temp[i]=s.at(i);
//     }
//     for (int i = 0; i < s.size(); i++)
//     {
//         cout<<temp[i];
//     }
    
    
//     return 0;
// }



// #include<iostream>
// #include<string>
// using namespace std;

// int main()
// {
//     char s[5];
//     string g;
    
//     // cin>>g;
//     // cout<<g;
//     //  cin.getline(g,5);
//      cout<<g;
//     return 0; 
// }


// #include <iostream>
// #include <string>
// using namespace std;
// int main ()
// {
//   string name;

//   cout << "Please, enter your full name: ";
//   getline (cin,name);
//   cout  << name ;

//   return 0;
// }


#include<iostream>
using namespace std;

int main()
{
   
	// Write your code here.
    string str;
    getline(cin,str);
    string s="@40";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==' ')
        {
            str.replace(i,1,"@50");  
        }
    }
    cout<<str;
    return 0;
}
   