class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char>mp = {
            {'(',')'},
            {'{', '}'},
            {'[', ']'}
        };
        stack<char> st;

        for(auto c : s){
            if(c == '(' || c == '{' || c == '[')
                st.push(c);
            else{
                if (st.empty())
                    return false;
                
                if (mp[st.top()] != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
