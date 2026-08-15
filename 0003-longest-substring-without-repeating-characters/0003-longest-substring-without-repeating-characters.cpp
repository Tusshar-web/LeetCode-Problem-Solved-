class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            // Character already exists in current window
            if (lastSeen.find(s[right]) != lastSeen.end()) {
                left = max(left, lastSeen[s[right]] + 1);
            }

            // Update last occurrence
            lastSeen[s[right]] = right;

            // Current window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};