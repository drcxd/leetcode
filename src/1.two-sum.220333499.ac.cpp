class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> lookup_table;
        vector<int> result;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int delta = target - nums[i];
            if (lookup_table.find(delta) != lookup_table.end())
            {
                result.push_back(lookup_table[delta]);
                result.push_back(i);                
                break;
            }
            else
            {
                lookup_table[nums[i]] = i;
            }
        }
        return result;
    }
};
