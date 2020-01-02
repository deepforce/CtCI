#include <string>
#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm> // for sort() 
using namespace std;

// Use a array to store frequency of each character in the string
// Analysis:
// Time: O(N)
// Space: O(1)  (128 * 8 bits vector)
bool isUniqueChars(const string & str) {
    // This is because ASCII only encodes 128 specified characters into seven-bit integers
    if (str.length() > 128) {
        return false;
    }
    vector<bool> char_set(128);
    for (int c : str) {
        // if the character already exists, return false
        if (char_set[c])
            return false;
        char_set[c] = true;
    }
    return true;
}

// Use a bitvector to store frequency of each character
// Reduce space usage by a factor of 8 using bitvector. 
// Each boolean otherwise occupies a size of 8 bits.
// Analysis:
// Time: O(N)
// Space: O(1) (256 bits bitset)
bool isUniqueChars_bitvector(const string &str) {
    bitset<256> bits(0);
    for (int c : str) {
        if (bits.test(c)) 
            return false;
        bits.set(c);
    }
    return true;
}

// If we can't use additional data structures, we can do the following:
// 1. Compare every character of the string to every other character of the string. 
// This will take O(N^2) time and O(1) Space
// 2. If we are allowed to modify the input string, we could sort the string in O(NlogN) time 
// and then check the string for neighboring characters that are identical.
bool isUniqueChars_noDS(string str) {
    sort(str.begin(), str.end());

    for (int i = 0; i < str.length()-1; i++) {
        if (str[i] == str[i+1]) {
            return false;
        }
    }
    return true;
}



int main() {
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars(word) <<endl;
		}
		cout <<endl << "Using bit vector" <<endl;
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) <<endl;
		}
		cout <<endl << "Using no Data Structures" <<endl;
		for (auto word : words)
		{
			cout << word << string(": ") << boolalpha << isUniqueChars_noDS(word) <<endl;
		}
		return 0;
}