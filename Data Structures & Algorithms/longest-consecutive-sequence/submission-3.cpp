class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxl = 0;
        for (int i : s){
            if (s.find(i-1) == s.end()){
                int current = i;
                int len = 1;
                while (s.find(current+1) != s.end()){
                    current++;
                    len++;
                }
                maxl = max(len, maxl);
            }
        }
        return maxl;
    }
};
