class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s;
        for (auto& num : nums)
            s.insert(num);
        int current = 0, len, maxL = 0;
        for (int i = 0; i < nums.size(); i ++){
            int x = nums[i];
            if (s.find(x-1) == s.end()){
                current = x;
                len = 1;
                while (s.find(current+1) != s.end()){
                    current++;
                    len++;
                }
                maxL = max(len, maxL); 
            }
                
        }
        return maxL;
    }
};
