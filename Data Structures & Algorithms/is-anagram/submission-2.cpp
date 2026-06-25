class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26, 0);
        int n = s.size();

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < n; i++)
            freq[s[i] - 'a']++;
        
        for (int j = 0; j < n; j++)
            freq[t[j] - 'a']--;

        for (auto& count: freq){
            if(count != 0)
                return false;
        }

        return true;
    }
};
