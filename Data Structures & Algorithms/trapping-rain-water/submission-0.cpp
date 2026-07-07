class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lMax(n), rMax(n);
        int lm = 0, rm = 0;
        for (int i = 0; i < n; i++){
            lm = max(lm, height[i]);
            lMax[i] =lm;
        }

        for (int i = n-1; i >= 0; i--){
            rm = max(rm, height[i]);
            rMax[i] = rm;
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            int water = min(lMax[i], rMax[i]) - height[i];
            ans += water;
        }

        return ans;
    }
};
