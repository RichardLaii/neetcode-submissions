class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        int cnt = 0;
        for (auto str : strs){
            cnt = str.size();
            s += to_string(cnt) + '@' + str;
        }
        return s;      
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '@')
                j++;
            string num = s.substr(i, j - i);
            int len = stoi(num);
            string str = s.substr(j + 1, len);
            ans.push_back(str);
            i = j + 1 + len;
        }
        return ans;
    }
};
