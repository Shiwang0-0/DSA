#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// bool jumpSearch(vector<int> v, int k)
// {
//     int jumpSize = sqrt(v.size());
//     int low = 0, high = 0;
//     for (int i = 0; i < v.size(); i = i + jumpSize)
//     {
//         low = i;
//         high = i + jumpSize - 1;

//         if (v[low] == k)
//         {
//             cout << "element is at index " << low;
//             return true;
//         }
//         else if (v[low] < k && v[high] > k)
//         {
//             break;
//         }
//     }
//     for (int j = low; j <= low+jumpSize && j<v.size(); j++)
//     {
//         if (v[j] == k)
//         {
//             cout << "element found at index " << j;
//             return true;
//         }
//     }
//     return false;
// }

bool jumpSearch(vector<int>v,int key)
{
    int jump=sqrt(v.size()),prev=0,step=0;
    while(step<v.size())
    {
        if(v[step]==key)
            return true;
        
        else if(v[step])
            
    }
}

int main()
{
    int key = 0;
    vector<int>  v = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << "enter element to be searched ";
    cin >> key;
    if (!(jumpSearch(v, key)))
    {
        cout << "element not found";
    }
    return 0;
}