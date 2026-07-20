class Solution {
public:

// Merge two sorted halves into a single sorted array
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary array to store merged result
    int left = low;   // Starting index of left half
    int right = mid + 1; // Starting index of right half

    // Merge elements in sorted order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int> &arr, int low, int mid , int high){
    int right = mid+1;
    int cnt = 0;
    for(int i = low; i <= mid; i++){
        while(right <= high && arr[i] > 2*(long long)arr[right]){ right ++;}
        cnt += (right - (mid+1));
    }
    return cnt;
}

// Recursive merge sort function
int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt; // Base case: single element
    int mid = low + (high - low) / 2;
    cnt += mergeSort(arr, low, mid);     // Sort left half
    cnt += mergeSort(arr, mid + 1, high); // Sort right half
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);   // Merge sorted halves
    return cnt;
}



    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums , 0 , n-1);
    }
};