class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int d = nums.size();
        if (d == 0) return;

        k %= d;

        vector<int> temp;

        // Store last k elements
        for (int i = d - k; i < d; i++) {
            temp.push_back(nums[i]);
        }

        // Shift remaining elements to the right
        for (int i = d - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }

        // Place saved elements at the beginning
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};