class Solution {
public:

    // Recursive function to generate all subsets while skipping duplicates
    void find_subsets_with_dup(int index, vector<int>& ds, vector<vector<int>>& ans, vector<int>& nums) {
        // Always include the current subset (even empty at the start)
        ans.push_back(ds);

        for (int i = index; i < nums.size(); i++) {
            // Skip duplicate elements at the same recursion level
            if (i != index && nums[i] == nums[i - 1]) continue;

            // Include the current element
            ds.push_back(nums[i]);

            // Recurse for next elements
            find_subsets_with_dup(i + 1, ds, ans, nums);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;               // temporary list to build subsets
        vector<vector<int>> ans;     // stores all unique subsets

        sort(nums.begin(), nums.end()); // sort to handle duplicates

        find_subsets_with_dup(0, ds, ans, nums);
        return ans;
    }
};


/*
Time Complexity: O(2^n)
- In the worst case (no duplicates), total subsets = 2^n
- For duplicates, fewer branches are explored due to skipping logic

Space Complexity: O(2^n * k)
- 2^n subsets, each of average size k
- Plus O(n) recursion stack space
*/
