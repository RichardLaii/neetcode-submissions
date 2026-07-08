class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int r = 0, l = 0;
        int n = s1.size();
        unordered_map <char, int> mp, freq;

        for (int i = 0; i < n; i++)
            freq[s1[i]]++;
            
        while (r < s2.size()){
            mp[s2[r]]++;
            if (r - l + 1 > n){
                mp[s2[l]]--;
                if (mp[s2[l]] == 0)
                    mp.erase(s2[l]);
                l++;
            }
            if (freq == mp)
                return true;
            r++;
        }
        return false;
    }
};
