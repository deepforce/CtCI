#include <iostream>
using namespace std;

// extend string length which will be long enough to accomodate extra chars + true len
// Analysis
// Time: O(N)
// Space: O(1)
void urlify (string &str, int len) {
    int numofSpaces = 0;
    for (int i = 0; i < len; i++)
        if (str[i] == ' ')
            numofSpaces++;

    int extendedLen = len + 2 * numofSpaces;

    int i = extendedLen - 1;
    for (int j = len-1; j >= 0; j--) {
        if (str[j] != ' ')
            str[i--] = str[j];
        else {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    } 
}

int main() {
    string str = "Mr John Smith    ";       //String with extended length ( true length + 2* spaces)
    std::cout << "Actual string   : " << str << std::endl;
    urlify(str, 13);                                        //Length of "Mr John Smith" = 13
    std::cout << "URLified string : " << str << std::endl;
    return 0;
}