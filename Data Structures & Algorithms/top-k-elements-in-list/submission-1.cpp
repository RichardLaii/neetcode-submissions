class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // bucket
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto &i : nums)
            mp[i]++;

        vector<vector<int>> bucket(n + 1);
        for (auto &freq : mp)
            bucket[freq.second].push_back(freq.first);

        vector<int> result;
        for (int i = n; i > 0; i--){
            for (auto &j : bucket[i]){
                result.push_back(j);

                if (result.size() == k)
                    return result;
            }
        }
            
    }
};
