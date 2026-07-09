class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int cnt = 0;
        int ctn1 = 0;
        int n = nums.size();
        for(int i = 0 ; i< n ; i++) {
            if(cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt ++;
            } else {
                cnt --;
            }
        }

        for(int i = 0 ; i < n ; i++ ) {
            if(el == nums[i]) {
                ctn1 ++;
            } if(ctn1 > (n/2)){
                return el;
            }
        }
        return -1;
    }
};