class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long sum = 0, ans = 0;
        int i = 0;
        unordered_map<int, int> mpp;

        int n = nums.size();

        while (i < k && i < n) {
            mpp[nums[i]]++;
            sum = sum + nums[i];
            i++;
        }

        if (mpp.size() == k) {
            ans = sum;
        }

        while (i < n) {
            mpp[nums[i]]++;
            mpp[nums[i - k]]--;
            if (mpp[nums[i - k]] == 0) {
                mpp.erase(nums[i - k]);
            }
            sum += nums[i];
            sum -= nums[i - k];
            if (mpp.size() == k) {
                ans = max(ans, sum);
            }
            i++;
        }
        return ans;
    }
};
