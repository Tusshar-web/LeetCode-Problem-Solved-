class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, maxSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < k; i++){
            leftSum = leftSum + cardPoints[i];
        }

        maxSum = leftSum;

        int rightInd = n-1;
        for(int i = k-1; i >= 0; i--){
            leftSum = leftSum - cardPoints[i];
            rightSum = rightSum + cardPoints[rightInd];
            int currSum = leftSum + rightSum;
            maxSum = max(maxSum , currSum);
            rightInd -=1;
        }
        return maxSum;
    }
};