class Solution {
public:
    int firstOcc(vector<int> &nums, int n , int k){
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low <= high){
            int mid =(low + high)/2;
            if(nums[mid] == k){
                first = mid;
                high = mid-1;
            } else if(nums[mid] < k) low = mid+1;
            else high = mid-1;
        }
        return first;
    }

    int lastOcc(vector<int> &nums, int n , int k){
        int low = 0;
        int high = n-1;
        int last = -1;
        while(low <= high){
            int mid =(low + high)/2;
            if(nums[mid] == k){
                last = mid;
                low = mid+1;
            } else if(nums[mid] < k) low = mid+1;
            else high = mid-1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOcc(nums , n , target);
        if(first == -1) return {-1,-1};
        int last = lastOcc(nums , n , target);
        return {first,last};
    }
};