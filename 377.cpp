class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.empty() && target == 0)
        	return 1;
        if (target <= 0)
        	return 0;

        vector<int> count(target + 1, 0);
        // count[i]: the combination number for target i
        count[0] = 1;
        for (int i = 1; i <= target; i++) {
			for (int num : nums) {
				if (num <= i)
					count[i] += count[i - num];
			}
        }

        return count[target];
    }
};