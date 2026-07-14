class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;

        int leftWall = 0;
        int rightWall = 0;

        int start = 0;
        int end = n-1;

        while(start < end) {
            leftWall = max(leftWall , height[start]);
            rightWall = max(rightWall , height[end]);

            if(leftWall < rightWall) {
                totalWater += leftWall - height[start];
                start ++;
            } else {
            totalWater += rightWall - height[end];
            end --;
        }
        }

        return totalWater;
    } 
};