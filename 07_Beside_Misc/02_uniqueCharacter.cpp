#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    // Count the occurrences of each character
    for (char c : s) {
        charCount[c]++;
    }

    // Find the index of the first non-repeating character
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    return -1; // If no non-repeating character is found
}

int main() {
    string s = "leetcode";

    int index = firstUniqChar(s);

    cout << "First non-repeating character index: " << index << endl;

    return 0;
}
