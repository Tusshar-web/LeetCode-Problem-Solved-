class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (s[i] == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--;  // Treat '*' as ')'
                maxOpen++;  // Treat '*' as '('
            }
            if (minOpen < 0) {
                minOpen = 0;
            }
            if (maxOpen < 0) {
                return false;
            }
        }

        return minOpen == 0;
    }
};