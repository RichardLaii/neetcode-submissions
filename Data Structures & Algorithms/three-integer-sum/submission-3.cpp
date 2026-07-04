class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<int> record;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-1; i++){
            int left = i+1, right = nums.size()-1;
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            while (left < right){
                if(nums[left] + nums[right] == -nums[i]){
                    record.push_back(nums[i]);
                    record.push_back(nums[left]);
                    record.push_back(nums[right]);
                    left++;
                    right--;
                    result.push_back(record);
                    record.clear();
                    while (left < right && nums[left] == nums[left-1])
                        left++;
                    while (left < right && nums[right] == nums[right+1])
                        right--;
                }
                else if (nums[left] + nums[right] < -nums[i])
                    left++;
                else if (nums[left] + nums[right] > -nums[i])
                    right--;
            }
        }
        return result;
    }
};
