class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length()) return false;
        string concat = goal+goal;
        int ind = concat.find(s);
        if(ind == -1) return false;
        else return true;
    }
};