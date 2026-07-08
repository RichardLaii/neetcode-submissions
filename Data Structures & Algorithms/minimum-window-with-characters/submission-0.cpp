class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int len = INT_MAX, best_l = 0;
        unordered_map<char, int> s_mp, t_mp;
        int n = t.size();

        for (int i = 0; i < n; i++)
            t_mp[t[i]]++;
        
        for (int r = 0; r < s.size(); r++){
            s_mp[s[r]]++;
            while(check(s_mp, t_mp)){
                if (r - l + 1 < len){
                    len = r - l + 1;
                    best_l = l;
                }
                s_mp[s[l]]--;
                l++;
            }
        }
        if (len == INT_MAX)
            return "";
        return s.substr(best_l, len);

    }

    bool check(unordered_map<char, int>& s_mp,
                unordered_map<char, int>& t_mp){

        for (auto& [k, cnt] : t_mp){
            if (s_mp[k] < cnt)
                return false;
        }
        return true;
    }
};
