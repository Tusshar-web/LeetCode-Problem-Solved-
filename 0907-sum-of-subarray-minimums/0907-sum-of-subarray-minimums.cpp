class Solution {
public:
    vector<int> NSE(vector<int>& arr , int n){
        stack<int> st;
        vector<int> nse(n,0);
        for(int i = n-1; i >= 0; --i){
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> PSEE(vector<int>& arr , int n){
        stack<int> st;
        vector<int> psee(n,0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            psee[i] = st.empty() ? -1:st.top();
            st.push(i);
        }
        return psee;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = (int)(1e9 + 7);
        long long sum = 0;
        vector<int> psee = PSEE(arr , n);
        vector<int> nse = NSE(arr , n);
        for(int i = 0; i < n; i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long totalOcc = (left * right) %mod;
            sum = (sum + (totalOcc * arr[i])%mod) %mod;
        }
        return sum;
    }
};