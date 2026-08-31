class Solution {
public:
    int getCnt(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < nums.size()){
            sum += (nums[r] % 2 != 0);
            while(sum > k){
                sum = sum - (nums[l] % 2);
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = getCnt(nums , k) - getCnt(nums , k-1);
        return res;
    }
};