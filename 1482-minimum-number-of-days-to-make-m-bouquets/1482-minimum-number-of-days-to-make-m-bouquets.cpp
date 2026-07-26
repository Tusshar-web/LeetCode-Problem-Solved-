class Solution {
public:
    bool possible(vector<int> &v, int days , int m , int k){
        int cnt = 0;
        int noOfBoq = 0;
        int n = v.size();
        for(int i = 0; i < n; i++){
            if(v[i] <= days) cnt ++;
            else {
                noOfBoq += (cnt/k);
                cnt = 0;
            }
        }
        noOfBoq += (cnt/k);
        return noOfBoq >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val = 1LL*m * 1LL*k;
        int mini = INT_MAX , maxi = INT_MIN;
        int n = bloomDay.size();
        if(n < val) return -1;
        
        for(int i = 0; i < n; i++){
            mini = min(mini , bloomDay[i]);
            maxi = max(maxi , bloomDay[i]);
        }
        int low = mini , high = maxi;
        while(low <= high){
            int mid = (low + high)/2;
            if(possible(bloomDay , mid , m , k)) high = mid-1;
            else low = low+1;
        }
        return low;
    }
};