#include <iostream>
#include <vector>
using namespace std;



// better one , returns the lps array

vector<int> prefix(const string& a) {
        int m = a.size();
        vector<int> table(m, 0);
        int j = 0;
        for (int i = 1; i < m; ++i) {
            while (j > 0 && a[i] != a[j]) 
                j = table[j - 1];
            
            if (a[i] == a[j]) 
                j++;
            table[i] = j;
        }

        return table;
    }

    
void findLPS(string pattern, vector<int>& lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pattern.size()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    cout << "LPS array: ";
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }
    cout << endl;
}



bool KMP(string text, string pattern, vector<int>& lps) {
    int i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.size()) {
            return true;
        } else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return false;
}

int main() {
    string text, pattern;

    // cout << "Enter text: ";
    // cin >> text;

    cout << "Enter pattern to search: ";
    cin >> pattern;

    vector<int> lps(pattern.size(), 0);
    findLPS(pattern, lps); 

    // if (KMP(text, pattern, lps))
    //     cout << "Target Found" << endl;
    // else
    //     cout << "Target Not Found" << endl;

    return 0;
}

// abcdgkxyzabcdgg
// eab
