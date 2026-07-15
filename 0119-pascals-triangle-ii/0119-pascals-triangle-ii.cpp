class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int row = rowIndex+1;
        vector<int> ansRow;
        long long ans = 1;
        ansRow.push_back(1);
        for(int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};