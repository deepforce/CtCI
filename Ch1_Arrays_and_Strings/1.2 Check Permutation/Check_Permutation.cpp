#include <iostream>
#include <algorithm>
using namespace std;
// Analysis
// Time: O(NlogN)
// Space: O(1)
bool arePermutation_sort(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    // If length of both strings is not same, then they
    // cannot be anagram
    if (n1 != n2)
        return false;

    // Sort both strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // Compare sorted strings
    for (int i = 0; i < n1; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

// Analysis
// Time: O(N) (N = max(n1,n2))
// Space: O(1) (256 32bits vector)
bool arePermutation_frequency(string str1, string str2) {
    // Count the number of each character in string1 and string2 and Compare them
    if (str1.length() != str2.length())
        return false;
    int count[256] = {0};
    for (int c : str1) {
        count[c]++;
    }
    for (int c : str2) {
        count[c]--;
        if (count[c] < 0)
            return false;
    }
    return true;
}
int main () {
    // Test Method 1 - Using sort
    cout << "Method 1 - Using sort" << endl;
    string str1 = "testest";
    string str2 = "estxest";
    if(arePermutation_sort(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
    if(arePermutation_sort(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;

//Test Method 2 - Using character count
    cout << "Method 2 - Using character count" << endl;
    str1 = "testest";
    str2 = "estxest";
    if(arePermutation_frequency(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    str1 = "hello";
    str2 = "oellh";
     if(arePermutation_frequency(str1, str2))
      cout << str1 <<" and " << str2 << " are permutation of each other" << endl;
    else
      cout << str1 <<" and " << str2 << " are not permutation of each other" << endl;
    return 0;
}