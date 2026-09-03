// #include<iostream>
// using namespace std;

// class Solution {
// public:
//     double equalizeWater(vector<int>& buckets, int loss) {
//         double l = 0, r = *max_element(buckets.begin(), buckets.end());
//         auto check = [&](double v) {
//             double a = 0, b = 0;
//             for (int x : buckets) {
//                 if (x > v) {
//                     a += x - v;
//                 } else {
//                     b += (v - x) * 100 / (100 - loss);
//                 }
//             }
//             return a >= b;
//         };
//         while (r - l > 1e-5) {
//             double mid = (l + r) / 2;
//             if (check(mid)) {
//                 l = mid;
//             } else {
//                 r = mid;
//             }
//         }
//         return l;
//     }
// };


// int main(){
//     int n=5;
//     int ele=(n>>1);
//     cout<<ele;
//     return 0;
// }






// #include<bits/stdc++.h>
// using namespace std;
 
// int main(void){
// 	int t(1), tcase(0);
// 	cin >> t; 
// 	while(++tcase, t--){
 
// 		string s;
// 		cin >> s; 
// 		int cnt0 = 0, cnt1 = 0, ans = 0;
// 		for(int i = 0; i < s.length(); ++i){
// 			if(s[i] == '0') ++cnt0;
// 			else ++cnt1;
// 		}
// 		int f = 0;
// 		for(int i = 0; i < s.length(); ++i){
// 			if(s[i] == '1' && cnt0 > 0){
// 				--cnt0;
// 			}else if(s[i] == '0' && cnt1 > 0){
// 				--cnt1;
// 			}else{
// 				f = s.length() - i;
// 				break;
// 			}
// 		}
// 		cout << f << endl;
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin>>n;
    int a[n];
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum%2)
    return "NO";
    return "YES";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<endl;
    }
    return 0;
}