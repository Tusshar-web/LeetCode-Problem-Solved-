class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(n != m) return false;

        unordered_map<char , int> mpp;

        for(int i = 0; i < n; i++){
            mpp[s[i]]++;
        }
         
        for(int i = 0; i < m; i++){
            if(mpp.find(t[i]) != mpp.end()) mpp[t[i]] -= 1;
            else return false;
        }

        for(auto item : mpp){
            if(item.second != 0) return false;
        }
        
        return true;
    }
};