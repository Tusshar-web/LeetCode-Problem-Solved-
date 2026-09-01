class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        unordered_map<char,int> mpp;
        int l = 0,  r = 0, minLen = INT_MAX, sInd = -1, m = t.size(),cnt = 0, n = s.size();
        for(int i = 0; i < m; i++){
            mpp[t[i]]++;
        }
        while(r < n){
            if(mpp[s[r]] > 0){
                cnt += 1;
            }
            mpp[s[r]]--;
            while(cnt == m){
                int len = r-l+1;
                if(len < minLen){
                    minLen = len;
                    sInd = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0){
                    cnt -=1;
                }
                l++;
            }
            r++;
        }
        return sInd == -1 ? "" : s.substr(sInd , minLen);
    }
};