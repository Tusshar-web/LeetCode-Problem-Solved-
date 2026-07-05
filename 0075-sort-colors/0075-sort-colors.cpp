class Solution {
public:
    void sortColors(vector<int>& nums) {
        quick_sort(nums , 0 , nums.size()-1);
    }
    void quick_sort(vector<int> &nums , int low ,int high){
            if(low<high){
                int pInd = partition(nums , low , high);
                quick_sort(nums, low , pInd-1);
                quick_sort(nums, pInd+1, high);
            }
        }
    int partition(vector<int>& nums , int low , int high){
        int pivot = nums[low];
        int i = low;
        int j = high;
        while(i<j){
            while(nums[i]<= pivot && i<=high-1) {
                i++;
            }
            while(nums[j]> pivot && j>=low+1){
                j--;
            }
            if(i<j){
                int temp = nums[i];
                nums[i]= nums[j];
                nums[j] = temp;
            }
        }
        int temp = nums[low];
        nums[low] = nums[j];
        nums[j] = temp;
        return j;
    }
};