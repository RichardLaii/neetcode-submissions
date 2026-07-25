class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int left, right;
        for (auto& token : tokens){
            if (token == "+"){
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left + right);
            }
            else if (token == "-"){
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left - right);
            }
            else if (token == "*"){
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left * right);
            }
            else if (token == "/"){
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left / right);
            }
            else
                st.push(stoi(token));
        }
        int ans = st.top();
        return ans;
    }
};
