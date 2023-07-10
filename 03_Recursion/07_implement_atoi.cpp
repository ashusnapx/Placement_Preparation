class Solution {
public:
    int helper(const string& s, int current_index) {
        if (current_index >= s.length() || s[current_index] == ' ') {
            // Base case: reached the end of the string or encountered whitespace
            return 0;
        }

        int sign = 1;
        if (s[current_index] == '-' || s[current_index] == '+') {
            sign = (s[current_index] == '-') ? -1 : 1;
            current_index++;
        }

        long result = 0;
        while (current_index < s.length() && isdigit(s[current_index])) {
            result = result * 10 + (s[current_index] - '0');
            current_index++;
        }

        // Handle overflow and underflow
        result *= sign;
        if (result < INT_MIN) {
            return INT_MIN;
        } else if (result > INT_MAX) {
            return INT_MAX;
        }

        return static_cast<int>(result);
    }

    int myAtoi(string s) {
        return helper(s, 0);
    }
};


/* 
The algorithm for myAtoi(string s) is as follows:

1. Read in and ignore any leading whitespace.
2. Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
3. Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
4. Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). 5. If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
6. If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
7. Return the integer as the final result.
*/