#include <iostream>
#include <bitset>
using namespace std;

/* For a string to be pallindrome, it should be able to spelled backward and forward the same.
 * Therefore the chars in string should fit one of the two possibilities:
 *  - Each char appear even number of times in the string ( even length string )
 *  - Each char should appear even number of times, except just one char ( odd length string )
 *
 */

// Approach 1: Check if the string have no more than one character that is odd
// Analysis
// Time: O(N)
// Space: O(1)

// Return the index of a character
int getCharIndex(char c) {
    int idx = -1;
    if (c >= 'a' && c <= 'z')
        idx = c - 'a';
    else if (c >= 'A' && c <= 'Z')
        idx = c - 'A';
    return idx;
}

// Calculate the frequency of each cahracter in a string
void countFrequency(const string str, int* freq) {
    int idx;
    for (const char c : str) {
        idx = getCharIndex(c);
        // must be alphabetical character
        if (idx != -1) {
            ++freq[idx];
        }
    }
}

// Check if the string have no more than one character that is odd
bool isPermutationOfPalindrome1(const string str ){
    int freq[26] = {0};
    countFrequency(str, freq);

    bool oddAppeared = false;
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 && oddAppeared)
            return false;
        else if (freq[i] % 2 && !oddAppeared)
            oddAppeared = true;
    }
    return true;
}

// Approach 2:
/*
 * Approach 2:
 * Let us optimize above function instead of taking another pass let us do it
 * in one go, we will count odd chars as we go along, if we are left with 
 * more that 0 or 1, then the input string can't have pallindrome permutation
 */
// Analysis
// Time: O(N)
// Space: O(1)

bool isPermutationOfPalindrome2( const string & str ) {
    int oddCount = 0;
    int frequency[26] = {0};
    int idx = 0;
    for (const char c : str) {
        idx = getCharIndex(c);
        if (idx != -1) {
            ++frequency[idx];
            if (frequency[idx] % 2)
                oddCount++;
            else 
                oddCount--;
        }
    }
    return (oddCount<=1);
}


/*
 * Approach 3
 * let us represent each char with a bit in a bitvector
 * Each time a char appears in the string we toggle the
 * respective bit, if we are left with more than 1 bit
 * in the bit vector, the string can not have a pallidrome
 * permutation.
 *
 */
// Analysis
// Time: O(N)
// Space: O(1)
bool isPermutationOfPalindrome3(const string str)
{
    bitset<27> bitVector;
    int id = 0;
    for ( const char c : str )
    {
        id = getCharIndex(c);
        if (id != -1)
            bitVector = bitVector.flip(id);
    }
    return ( bitVector.to_ulong() == 0 || bitVector.count() <= 1 );
}

int main() {
    std::string str("Tact Coa");
    std::cout << "Does \"" << str << "\"  has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    std::cout << "Approach 1:" << isPermutationOfPalindrome1( str ) << std::endl;
    std::cout << "Approach 2:" << isPermutationOfPalindrome2( str ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPalindrome3( str ) << std::endl;


    std::string str1("A big Cat");
    std::cout << "Does \"" << str1 << "\" has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    std::cout << "Approach 1:" << isPermutationOfPalindrome1( str1 ) << std::endl;
    std::cout << "Approach 2:" << isPermutationOfPalindrome2( str1 ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPalindrome3( str1 ) << std::endl;


    std::string str2("Aba cbc");
    std::cout << "Does \"" << str2 << "\" has a string whose permutation is a pallindrome? "
              << "( 1 for true, 0 for false ) : ";
    std::cout << "Approach 1:" << isPermutationOfPalindrome1( str2 ) << std::endl;
    std::cout << "Approach 2:" << isPermutationOfPalindrome2( str2 ) << std::endl;
    std::cout << "Approach 3:" << isPermutationOfPalindrome3( str2 ) << std::endl;
    return 0;
}
