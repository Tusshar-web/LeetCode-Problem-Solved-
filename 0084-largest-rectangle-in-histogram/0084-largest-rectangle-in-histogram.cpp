class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxRec = 0;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                
                int lb = nse - pse -1;
                maxRec = max(maxRec, heights[ele] * lb);
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele = st.top();
            st.pop();

            int nse = n;
            int pse = st.empty() ? -1 : st.top();

            int lb = nse - pse - 1;
            maxRec = max(maxRec, heights[ele] * lb);
        }
        return maxRec;
    }
};