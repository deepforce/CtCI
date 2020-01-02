#include <iostream>
#include <string>
using namespace std;

// We iterate through the string, copying characters to a new string 
// and counting the repeats.
// Analysis
// Time: O(N)
// Space: O(N)
string compress(string str) {
    size_t original_length = str.length();
    if (original_length < 2) {
        return str;
    }
    string out{""};
    int count  = 1;
    for (size_t i = 1; i < original_length; ++i) {
        if (str[i-1] == str[i])
            count++;
        else {
            out+=str[i-1];
            out+=to_string(count);
            count=1;
        }
        if (out.length() >= original_length)
            return str;
    }
    out += str[original_length-1];
    out += to_string(count);
    if (out.length() >= original_length)
            return str;
    return out;
}


int main() {
    std::string str, out;
    str = "aabcccccaaa";
	out = compress(str);
	if (str.compare(out)) {
		std::cout << str << " can be compressed to " << out << std::endl;
	} else {
		std::cout << str << " can not be compressed\n";
	}
	return 0;
}