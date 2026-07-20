class Solution {
public:
    int characterReplacement(string s, int k) {
        int r = 0, l = 0;
        int ans = 0;
        int cnt = 0;
        unordered_map<char, int> mp;
        while (r < s.size()){
            mp[s[r]]++;
            cnt = max(cnt, mp[s[r]]); 
            while (r - l + 1 - cnt > k){
                mp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
