class Solution {
public:
    // int findDuplicate(vector<int> &nums) {
    //     int fast = 0, slow = 0;
    //     do {
    //         slow = nums[slow];
    //         fast = nums[nums[fast]];
    //     } while (fast != slow);

    //     fast = 0;
    //     while (fast != slow) {
    //         slow = nums[slow];
    //         fast = nums[fast];
    //     }
    //     return fast;
    // }

    int findDuplicate(vector<int> &nums) {
        int low = 0, high = nums.size() - 1;
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            int count = 0;
            for (int n : nums) {
                if (n <= mid) {
                    ++count;
                }
            }
            if (count <= mid) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
private:
};