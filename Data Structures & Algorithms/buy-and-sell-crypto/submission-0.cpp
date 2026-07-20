class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<int, int> mp;
        // l = buy, r = sell
        int r = 0, l = 0;
        int ans = 0;
        
        while (r < prices.size()){
            if (prices[l] > prices[r])
                l = r;
            ans = max(ans, prices[r] - prices[l]);
            r++;
        }
        return ans;
    }
};
