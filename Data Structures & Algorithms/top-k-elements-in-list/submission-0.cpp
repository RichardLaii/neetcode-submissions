class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> cnt;
        for (auto &count : mp)
            cnt.push_back(count);
        sort(cnt.begin(), cnt.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b){
                return a.second > b.second;
            });
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(cnt[i].first);

        sort(result.begin(), result.end());
        return result;
    }
};
