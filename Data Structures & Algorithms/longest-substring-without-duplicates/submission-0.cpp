class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int r = 0;
        int l = 0;
        int ans = 0;
        while (r < s.size()){
            mp[s[r]]++;
            while (mp[s[r]] > 1){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        
        return ans;
    }
};
// bbbb
/*
brl
143   
*/
