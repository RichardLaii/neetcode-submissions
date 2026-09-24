class Solution {
public:

    string encode(vector<string>& strs) {
        int count = 0;
        string s;
        for (auto word : strs){
            count = word.size();
            s += to_string(count) + "#" + word;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#')
                j++;
            
            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            ans.push_back(str);
            i = j + 1 + len;
        }
        return ans;
    }
};
