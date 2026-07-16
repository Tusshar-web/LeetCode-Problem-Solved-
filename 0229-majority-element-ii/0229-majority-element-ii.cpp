class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int mini = (int) (n/3) +1;
        int ctn1 = 0 , ctn2 = 0;
        int ele1 = 0 , ele2 = 0;

        for(int i = 0; i < n; i++){
            if(ctn1 == 0 && nums[i] != ele2) {
                ctn1 ++;
                ele1 = nums[i];
            }
            else if(ctn2 == 0 && nums[i] != ele1) {
                ctn2 ++;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]) ctn1++;
            else if(ele2 == nums[i]) ctn2++;

            else {
                ctn1 -- , ctn2 --;
            }
        }

        vector<int> ls;
        ctn1 = 0;
        ctn2 = 0;

        for(int i = 0; i < n; i++){
            if(ele1 == nums[i]) ctn1++;
            else if(ele2 == nums[i]) ctn2++;
        }
        if(ctn1 >= mini) ls.push_back(ele1);
        if(ctn2 >= mini) ls.push_back(ele2);

        return ls;
    }
};