class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        while(left <= right){
            int k = left + (right - left) / 2;
            int hours = 0;
            for (int i = 0; i < piles.size(); i++){
                hours += piles[i] / k;
                if (piles[i] % k > 0)
                    hours++;
                //if (hours > h)
                //    break;
            }
            if (hours > h)
                left = k + 1;
            else{
                right = k - 1;
                ans = min(ans, k);
            }
            
        }
        return ans;
    }
};
