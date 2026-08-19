class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int cur = st.top();
                st.pop();
                int right = i;
                int left = st.empty() ? -1 : st.top();
                int width = right - left - 1;
                ans = max(ans, heights[cur] * width);
            }
            st.push(i);
        }
        return ans;
    }
};
