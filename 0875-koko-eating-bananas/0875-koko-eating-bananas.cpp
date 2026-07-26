class Solution {
public:
    int maxEle(vector<int>& v) {
        int maxi = INT_MIN;
        for (int x : v)
            maxi = max(maxi, x);
        return maxi;
    }

    long long calHr(vector<int>& v, int speed) {
        long long totalH = 0;
        for (int x : v) {
            totalH += (1LL * x + speed - 1) / speed;
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxEle(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (calHr(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};