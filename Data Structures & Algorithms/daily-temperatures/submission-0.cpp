class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result;
        for (int i = 0; i < n; i++){
            int days = 0;
            for (int j = i + 1; j < n; j++){
                if (temperatures[j] > temperatures[i]){
                    days = j - i;
                    break;
                }
                    
            }
            result.push_back(days);
        }
        return result;
    }
};
