class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, maxLen = 0;
        unordered_map<int , int> basket;
        while(r < fruits.size()){
            basket[fruits[r]]++;
            if(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            if(basket.size() <= 2){
                int len = r-l+1;
                maxLen = max(maxLen , len);
            }
            r++;
        }
        return maxLen;
    }
};