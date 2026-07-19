class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> close = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (auto& c : s){
            if (close.count(c)){
                if (!st.empty() && st.top() == close[c])
                    st.pop();
                else
                    return false;
            }
            else
                st.push(c);
        }
        return st.empty();
        
    }
};
