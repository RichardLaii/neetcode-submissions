class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        int ans;
        int i = 0;
        while(i < nums.size()){
            ans = target - nums[i];
            if(mp.find(ans) != mp.end())
                return {mp[ans], i};
            else
                mp[nums[i]] = i;
            i++;
        }
    }
};
