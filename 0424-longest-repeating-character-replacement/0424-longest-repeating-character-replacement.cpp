class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxFreq = 0, maxLen = 0;
        unordered_map<char, int> count;
        
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);
            while ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};