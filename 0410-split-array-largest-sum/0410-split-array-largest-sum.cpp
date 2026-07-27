class Solution {
public:
    int countPainters(vector<int> &v , int days){
        int painter = 1;
        int paintdays = 0;
        for(int i = 0; i < v.size(); i++){
            if(paintdays + v[i] <= days) paintdays += v[i];
            else {
                painter ++;
                paintdays = v[i];
            }
        }
        return painter;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) return -1;
        int low = *max_element(nums.begin() , nums.end());
        int high = accumulate(nums.begin() , nums.end() , 0);
        while(low <= high){
            int mid = (low + high)/2;
            if(countPainters(nums , mid) <= k) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};